MOD = 998244353
n = int(input())
a = list(map(int, input().split()))
p = 0
q = 1
for i in range(n):
	p = 100 * (p + q) % MOD
	q = q * a[i] % MOD
print(p * pow(q, MOD - 2, MOD) % MOD)