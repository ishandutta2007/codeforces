w, m = list(map(int,input().split()))

def bt(w, p, final, cur):
    if final == cur:
        return True

    if p == 0:
        return False

    if abs(cur + p - final) <= (p - 1) / (w - 1):
        if bt(w, p // w, final, cur + p):
            return True

    if abs(cur - p - final) <= (p - 1) / (w - 1):
        if bt(w, p // w, final, cur - p):
            return True

    if bt(w, p // w, final, cur):
        return True

    return False

if bt(w, w ** 35, m, 0):
    print("YES")
else:
    print("NO")