x = int(raw_input())
h,m = map(int, raw_input().split())
ans = 0
while ("7" not in str(h) and "7" not in str(m)):
    ans += 1
    m -= x
    if m < 0:
        m += 60
        h -= 1
        if h < 0:
            h += 24
print ans