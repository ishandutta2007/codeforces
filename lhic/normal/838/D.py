MOD = 10 ** 9 + 7
n, m = input().split(' ')
n = int(n)
m = int(m)
ans = pow(2 * (n + 1), m, MOD)
ans = (ans * (n + 1 - m)) % MOD
ans = (ans * pow(n + 1, MOD - 2, MOD)) % MOD
print(ans)