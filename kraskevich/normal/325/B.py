def f(x, k):
    return x * (x - 1) // 2 + ((2 ** k) - 1) * x

res = []
n = int(input())
for k in range(0, 64):
    l = 1
    r = 2 ** 100
    while l < r:
        m = (l + r) // 2
        cur = f(m, k)
        if cur < n:
            l = m + 1
        else:
            r = m
    if f(l, k) != n or l % 2 == 0:
        continue
    cand = (2 ** k) * l
    if not (cand in res):
        res.append(cand)
if len(res) == 0:
    res.append(-1)
for x in sorted(res):
    print(x)