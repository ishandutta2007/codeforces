m, s = map(int,input().split())
if m == 1 and s == 0:
    print("0 0")
elif s == 0 or s > 9 * m:
    print("-1 -1")
else:
    x = ""
    y = ""
    a = 9 * m - s
    b = s
    for i in range(m):
        if i == 0:
            t = min(min(9, a), 8)
            x += str(9 - t)
            a -= t
        else:
            t = max(min(9, a), 0)
            x += str(9 - t)
            a -= t
        u = min(9, b)
        y += str(u)
        b -= u
    print(int(x),int(y))