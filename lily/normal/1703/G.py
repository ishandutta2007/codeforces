T = int(input())
while T > 0:
    T -= 1
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    ans = 0
    cur = 0
    for i in range(n):
        v = cur
        d = 1
        for j in range(i, min(i + 31, n)):
            d *= 2
            v += a[j] // d
        ans = max(ans, v)
        cur -= k
        cur += a[i]
    print(max(ans, cur))