n, m, a = map(int, input().split())

x = (n + a - 1) // a
y = (m + a - 1) // a

print(x * y)