TC = int(input())

for tc in range(TC):
    n = int(input())
    s = input()
    chars = set()
    res = True
    active = '$'
    for c in s:
        if c in chars:
            if (c != active):
                res = False
        chars.add(c)
        active = c
    print("Yes" if res else "No")