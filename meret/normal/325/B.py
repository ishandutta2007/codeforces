n = int(input())
res = set()
for r in range(100):
    a = 1
    b = 2**(r + 1) - 3
    c = -2 * n
    d = b * b - 4 * a * c
    if d < 0:
        continue
    le = 0
    ri = d
    while le < ri:
        c = (le + ri) // 2
        if c * c < d:
            le = c + 1
        else:
            ri = c
    if le * le == d:
        if (-b - le) % 4 == 2 and -b - le > 0:
            res.add((-b - le) // 2 * 2**r)
        if (-b + le) % 4 == 2 and -b + le > 0:
            res.add((-b + le) // 2 * 2**r)
for i in sorted(list(res)):
    print(i)
if not list(res):
    print(-1)