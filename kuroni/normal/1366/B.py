te = int(input())
for t in range(te):
    n, tmp, m = [int(x) for x in input().split()]
    l, r = tmp, tmp
    for i in range(m):
        tl, tr = [int(x) for x in input().split()]
        if max(l, tl) <= min(r, tr):
            l = min(l, tl)
            r = max(r, tr)
    print(r - l + 1)