n, m = map(int, input().split(' '))
res = 0
while n <= m:
    res += 1
    n *= 3
    m *= 2
print(res)