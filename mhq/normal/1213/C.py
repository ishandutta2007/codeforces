import math
tst = int(input())
for _ in range(tst):
    b, a = map(int, input().split())
    b //= a
    cnt = b // 10
    sum = 0
    for i in range(1, 11):
        sum += (a * i) % 10
    sum *= cnt
    for i in range(1, b % 10 + 1):
        sum += (a * i) % 10
    print(sum)