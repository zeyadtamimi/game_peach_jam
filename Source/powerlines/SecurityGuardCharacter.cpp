// Fill out your copyright notice in the Description page of Project Settings.

#include "SecurityGuardCharacter.h"
#include "SecurityGuardController.h"


ASecurityGuardCharacter::ASecurityGuardCharacter()
{
	State = EPlayerState::IDLE;
	Alive = true;
}

void ASecurityGuardCharacter::Tick(float DeltaSeconds)
{
	UpdateCharacter();
	Super::Tick(DeltaSeconds);
}



void ASecurityGuardCharacter::UpdateCharacter()
{
	UpdateCharacterState();
	// Update animation to match the motion
	UpdateAnimation();
}

void ASecurityGuardCharacter::UpdateCharacterState()
{
	const float CharacterVelocity = GetVelocity().SizeSquared();
	State = (CharacterVelocity > 0.0f) ? EPlayerState::RUN : EPlayerState::IDLE;
}

void ASecurityGuardCharacter::UpdateAnimation()
{
	switch (State)
	{
	case EPlayerState::IDLE:
		GetSprite()->SetFlipbook(IdleAnimation);
		break;
	case EPlayerState::RUN:
		GetSprite()->SetFlipbook(RunningAnimation);
		break;
	default:
		GetSprite()->SetFlipbook(IdleAnimation);
	}
}