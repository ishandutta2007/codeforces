x1, y1, x2, y2 = map(int, input().split())

dx, dy = (x2 - x1) // 2, (y2 - y1) // 2
print(dx + 1 + (2 * dx + 1) * dy)