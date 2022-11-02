n, m = map(int, raw_input().split())
numb = 0
rowl, rowr, coll, colr = 1000, -1, 1000, -1
for r in range(n):
    s = raw_input()
    for c in range(m):
        if s[c] == 'B':
            rowl = min(rowl, r)
            rowr = max(rowr, r)
            coll = min(coll, c)
            colr = max(colr, c)
            numb += 1

if numb == 0: print 1
else:
    len = max(rowr - rowl, colr - coll) + 1
    if len > n or len > m: print -1
    else: print len ** 2 - numb