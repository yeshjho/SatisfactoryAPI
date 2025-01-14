// Copyright Coffee Stain Studios. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "FGVersionFunctionLibrary.generated.h"

UENUM( BlueprintType )
enum class EGameVersion : uint8
{
	GV_Main					UMETA( DisplayName = "Main" ),
	GV_Experimental			UMETA( DisplayName = "Experimental" ),
	GV_ClosedBeta			UMETA( DisplayName = "Closed Beta" ),
	GV_Other				UMETA( DisplayName = "Other" )
};

UCLASS()
class FACTORYGAME_API UFGVersionFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	/**
	 * Get a version string to show to the user
	 */
	UFUNCTION( BlueprintPure, Category = "Version")
	static FString GetVersionString();
	
	/**
	 * Returns true if this build is a public build (ie, consumable for the public)
	 */
	UFUNCTION( BlueprintPure, Category = "Version" )
	static bool IsPublicBuild();

	/**
	 * Returns true if this build is a closed beta build (with additional protections in place)
	 */
	UFUNCTION( BlueprintPure, Category = "Development" )
	static bool IsClosedBetaBuild();

	/** Returns true if the watermark should be visible */
	UFUNCTION( BlueprintPure, Category = "Development" )
	static bool IsWatermarkVisible();

	/** Get what version of the game we are running */
	UFUNCTION( BlueprintPure, Category = "Development" )
	static EGameVersion GetGameVersion();
};