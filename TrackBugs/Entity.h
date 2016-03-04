#import <SpriteKit/SpriteKit.h>

typedef enum : uint8_t {
  ColliderTypePlayer      = 1,
  ColliderTypeEnemyA       = 2,
  ColliderTypeEnemyB      = 4,
    
} ColliderType;

@interface Entity : SKSpriteNode

@property (assign,nonatomic) CGPoint direction;
@property (assign,nonatomic) float   health;
@property (assign,nonatomic) float   maxHealth;

//+ (SKTexture *)generateTexture;
- (instancetype)initWithPosition:(CGPoint)position;
- (void)update:(CFTimeInterval)delta;

/**
 Called to configure the physics body that will be used to handle collison detection. The collision body is a shape that covers the area of the entity with which collisions should be reported
 */
- (void)configureCollisionBody;

/**
 Called when a collision is detected so that some action can be taken e.g. reduce health or maybe collect a powerup
 @param body the physics body with which the physics body for this entity has collided
 */
- (void)collidedWith:(SKPhysicsBody *)body contact:(SKPhysicsContact*)contact;

@end
