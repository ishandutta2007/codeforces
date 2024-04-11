T = int(input())
while T > 0:
    T -= 1
    n = int(input())
    w = 0
    while w * w < n:
        w += 1
    ans = [0 for i in range(n)]
    while n > 1:
        while (w - 1) * (w - 1) >= n - 1:
            w -= 1
        to = w * w - (n - 1)
        for i in range(to, n):
            ans[i] = w * w - i
        n = to
    for i in range(len(ans)):
        print(ans[i], end='\n' if i == len(ans) - 1 else ' ')