def main():
    n, r, avg = map(int, input().split())

    need = avg * n

    d = sorted([list(map(int, input().split())) for _ in range(n)], key = lambda x: x[1])
    cur = sum(x[0] for x in d)
    #print(d, cur)
    ret = 0
    left = need - cur
    if left <= 0:
        return 0
    for x in d:
        can = min(r - x[0], left)
        ret += can * x[1]
        left -= can
        if left == 0:
            return ret

print(main())