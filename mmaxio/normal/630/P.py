from math import sin, cos, pi

n, r = map(int, input().split())

print(n * r**2 * sin(pi / n) * cos(pi * (n // 2) / n) / cos(pi * (n // 2 - 1) / n))