MOD = 10**9 + 7

def msum(n):
    return ((n * (n + 1)) // 2) % MOD

def main1():
    A, B = list(map(int, input().split()))
    S = 0

    for i in range(1,B):
        lo = i
        hi = (A + 1) * i - 1
        t = (msum(hi) - msum(lo - 1)) % MOD
        while t < 0:
            t += MOD
        cur = (i * (hi - lo + 1) + B * t) % MOD
        while cur < 0:
            cur += MOD

        S = (S + cur) % MOD

    print(S)

def main2():
    A, B = list(map(int, input().split()))
    sol = (B - 1) * B * A *(2 + B * (A + 1)) // 4
    print(sol % MOD)

main2()