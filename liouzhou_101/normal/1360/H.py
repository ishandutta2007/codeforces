for _ in range(int(input())):
    n, k = map(int, input().split())
    a = [int(input(), 2) for i in range(n)]
    L, R = 0, 2**k-1
    r = R
    while L <= R:
        m = (L+R)//2
        c = m+1 - sum(x <= m for x in a)
        if c >= (2**k-n+1)//2: r, R = m, m-1
        else: L = m+1
    while r in a: r -= 1
    print(("{0:0%db}" % k).format(r))