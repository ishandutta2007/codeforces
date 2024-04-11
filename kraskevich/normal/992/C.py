x, k = map(int, input().split())
mod = 1000 * 1000 * 1000 + 7
if x == 0:
    print(0)
else:
    mul = pow(2, k + 1, mod)
    cnt = pow(2, k, mod)
    s1 = mul * cnt * x
    s2 = cnt * (cnt - 1)
    ans  = (s1 - s2) % mod
    rev = pow(cnt, mod - 2, mod)
    assert rev * cnt % mod == 1
    ans *= rev
    print(ans % mod)