from sys import stdin
input = stdin.readline

MOD = 998244353
for _ in range(int(input())):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    where = [0] * n
    for i in range(n):
        where[a[i] - 1] = i
    for i in range(k):
        b[i] = where[b[i] - 1]

    sp = [-1] * n
    for i in range(k):
        sp[b[i]] = i

    def solve(sp):
        res = [0] * k
        mx = n
        for i in reversed(range(0, n)):
            if sp[i] == -1:
                mx = -1
            else:
                res[sp[i]] = 1 if mx < sp[i] else 0
                mx = max(mx, sp[i])

        return  res


    ans1 = solve(sp)
    sp.reverse()
    ans2 = solve(sp)
    ans = 1
    for i in range(k):
        ans *= ans1[i] + ans2[i]
        ans %= MOD

    print(ans)