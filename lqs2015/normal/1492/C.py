n, m = map(int, input().split(' '))
s = input()
t = input()
pre = [0] * m
suf = [0] * m
nt = [[-1 for y in range(26)] for x in range(n + 1)]
pr = [[-1 for y in range(26)] for x in range(n + 1)]
for i in range(n - 1, -1, -1):
    for j in range(26):
        nt[i][j] = nt[i + 1][j]
    nt[i][ord(s[i]) - ord('a')] = i
for i in range(1, n + 1):
    for j in range(26):
        pr[i][j] = pr[i - 1][j]
    pr[i][ord(s[i - 1]) - ord('a')] = i
cur = 0
for i in range(m):
    cur = nt[cur][ord(t[i]) - ord('a')]
    pre[i] = cur
    cur += 1
cur = n
for i in range(m - 1, -1, -1):
    cur = pr[cur][ord(t[i]) - ord('a')]
    suf[i] = cur - 1
    cur -= 1
ans = 0
for i in range(m - 1):
    ans = max(ans, suf[i + 1] - pre[i])
print(ans)