import math
tst = int(input())
for i in range(tst):
    n = int(input())
    a = list(map(int, input().split()))
    a.reverse()
    mn = a[0] + 100
    cnt = 0
    for c in a:
        if mn < c:
            cnt += 1
        mn = min(mn, c)
    print(cnt)