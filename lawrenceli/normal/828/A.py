n, a, b = map(int, raw_input().split())
t = list(map(int, raw_input().split()))
c, ans = 0, 0
for i in t:
    if i == 1:
        if a > 0: a -= 1
        elif b > 0: b, c = b - 1, c + 1
        elif c > 0: c -= 1
        else: ans += 1
    elif b > 0: b -= 1
    else: ans += 2
print ans