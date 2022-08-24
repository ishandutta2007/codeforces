import math
tst = int(input())
for i in range(tst):
    a = list(map(int, input().split()))
    a.sort()
    print((a[0] + a[1] + a[2]) // 2)