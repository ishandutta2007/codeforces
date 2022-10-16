A, B, n, x = map(int, input().split())

def fast_exp(A, n, m):
    if n == 0:
        return 1
    if n & 1:
        return A * fast_exp(A, n - 1, m) % m
    return fast_exp(A * A % m, n // 2, m)

def mod(a, m):
    a %= m
    if a < 0:
        a += m
    return a

m = 10**9 + 7

if A == 1:
    print(mod(x + n * B, m))
else:
    ans = B * mod(fast_exp(A, n, m) - 1, m) % m * fast_exp(A - 1, m - 2, m) % m + fast_exp(A, n, m) * x % m
    ans %= m

    print(ans)