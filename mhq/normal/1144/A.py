tst = int(input())
for i in range(0, tst):
    s = input()
    all = [0] * 26
    ok = True
    for c in s:
        all[ord(c) - ord('a')] += 1
    le = 0
    r = 25
    for j in range(0, 26):
        if all[j] > 1:
            ok = False
        if all[j]:
            le = max(le, j)
            r = min(r, j)
    ll = le
    le = r
    r = ll
    for j in range(0, 26):
        if j >= le and j <= r:
            ok &= (all[j] > 0)
        else:
            ok &= (all[j] == 0)
    if ok:
        print("Yes")
    else:
        print("No")