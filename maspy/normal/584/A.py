n, t = map(int, input().split())
x = 10**(n - 1)
while x % t != 0:
    x += 1
if x >= 10**n:
    print(-1)
else:
    print(x)