n, m = map(int, input().split())
c = list(map(int, input().split()))
k = list(map(int, input().split()))
p = [0] * m
c = [o - 1 for o in c]
s = sum(k)
ok = k.count(0)
i1 = 0
i2 = 0
while i2 < n and ok < m:
    p[c[i2]] += 1
    if p[c[i2]] == k[c[i2]]:
        ok += 1
    i2 += 1
if ok != m:
    print(-1)
    exit(0)
ans = i2 - i1
while i1 < n:
    p[c[i1]] -= 1
    while i2 < n and p[c[i1]] < k[c[i1]]:
        p[c[i2]] += 1
        i2 += 1
    if p[c[i1]] >= k[c[i1]]:
        ans = min(ans, i2 - i1 - 1)
    elif i2 == n:
        break
    i1 += 1
print(ans - s)