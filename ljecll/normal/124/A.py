n, a, b = map(int, input().split())

print(min(n - a - 1, b) + 1)