n = int(raw_input())

th = []
tm = []
for i in range(n):
    h,m = map(int, raw_input().split(":"))
    th.append(h)
    tm.append(m)

mx = 0
for i in range(n):
    mn = 24 * 60 - 1
    for j in range(n):
        a1 = th[i] * 60 + tm[i]
        a2 = th[j] * 60 + tm[j]-1
        if a2 < a1:
            a2 += 24 * 60
        mn = min(mn, a2 - a1)
    mx = max(mx, mn)

print "%02d:%02d\n" % (mx / 60, mx % 60)