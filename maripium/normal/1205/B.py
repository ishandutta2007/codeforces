import sys
from collections import deque

n = int(input())
a = list(map(int, input().split()))
na = list()
for x in a:
    if (x):
        na.append(x)
a = na
n = len(a)
for b in range(60):
    cnt = 0
    for x in a:
        if (x >> b & 1):
            cnt += 1
    if (cnt >= 3) :
        print(3)
        sys.exit()
g = [list() for x in range(n)]
for i in range(n):
    for j in range (n):
        if (i != j and (a[i] & a[j])):
            g[i].append(j)
ans = 200
def go(r):
    global ans
    d = [-1 for x in range(n)]
    q = deque()
    d[r] = 0
    q.append(r)
    while (len(q)):
        v = q.popleft()
        for u in g[v]:
            if (d[u] == -1):
                d[u] = d[v] + 1
                q.append(u)
            elif (d[u] >= d[v]):
                ans = min(ans, d[v] + d[u] + 1)
for r in range(n):
    go(r)
if (ans > n) :
    ans = -1
print(ans)