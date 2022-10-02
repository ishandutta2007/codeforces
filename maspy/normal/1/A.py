a, b, c = map(int, input().split())
x = (a + c - 1) // c
y = (b + c - 1) // c
print(x * y)