import copy
def flip(a, n):
    x = ['0' * n for i in range(n)]    
    for i in range(n):
        for j in range(n):
            x[n - 1 - j][n - 1 - i] = a[i][j]
    a = x
for _ in range(int(input())):
    n = int(input())
    a = []
    for j in range(n):
        a.append(input())
    ans = 0
    vis = [[False for i in range(n)] for j in range(n)]
    for i in range(n):
        for j in range(n):
            if vis[i][j]:continue
            u, v = i, j
            cnt = [0] * 2
            while (True):
                u, v = v, n - 1 - u
                vis[u][v] = True
                cnt[int(a[u][v]) - int('0')] += 1 
                if u == i and v == j:break
            ans += cnt[0] + cnt[1] - max(cnt[0], cnt[1])
    print(ans)