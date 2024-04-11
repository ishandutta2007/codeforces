from math import ceil
m, n, a = map(int,input().split())
x = ceil(m/a)
y = ceil(n/a)
ans = x * y
print(int(ans))