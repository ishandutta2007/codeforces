for _ in range(int(input())):
    n, k = map(int, input().split())
    a = [list(map(int, input().split()))[1:] for i in range(k)]

    def query(a):
        print("?", len(a), *a)
        return int(input())

    mval = query(list(range(1, n+1)))
    res = [0]*k

    def solve(L, R):
        if L == R:
            tmp = []
            for x in range(1, n+1):
                if x not in a[L]:
                    tmp.append(x)
            res[L] = query(tmp)
            return
        m = (L+R)//2
        tmp = []
        for b in a[L:m+1]:
            tmp.extend(b)
        Lc = query(tmp)
        if Lc == mval:
            for i in range(m+1, R+1): res[i] = mval
            solve(L, m)
        else:
            for i in range(L, m+1): res[i] = mval
            solve(m+1, R)
    solve(0, k-1)
    print("!", *res)
    input()