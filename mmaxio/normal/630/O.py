px, py, vx, vy, a, b, c, d = map(int, input().split())

vl = (vx**2 + vy**2)**0.5
vx /= vl
vy /= vl

print(px + vx * b, py + vy * b)

print(px - vy * a / 2, py + vx * a / 2)
print(px - vy * c / 2, py + vx * c / 2)
print(px - vy * c / 2 - vx * d, py + vx * c / 2 - vy * d)

print(px + vy * c / 2 - vx * d, py - vx * c / 2 - vy * d)
print(px + vy * c / 2, py - vx * c / 2)
print(px + vy * a / 2, py - vx * a / 2)