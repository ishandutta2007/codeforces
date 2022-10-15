T = int(input())
while T > 0:
    T -= 1
    n = int(input())
    a = list(map(int, input().split()))
    c = [0 for i in range(n)]
    ans = 0
    cnt = 0
    for i in range(n - 1, -1, -1):
        if a[i] <= i:
            ans += cnt
            if a[i] >= 1:
                c[a[i] - 1] += 1
        cnt += c[i]
    print(ans)