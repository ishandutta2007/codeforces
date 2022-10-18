a, b, c = map(int, input().split())

d = (b * b - 4 * a * c)**0.5
x1, x2 = (-b - d) / (2 * a), (-b + d) / (2 * a)

print(max(x1, x2))
print(min(x1, x2))