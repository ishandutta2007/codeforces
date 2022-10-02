MOD = 10**9 + 7
PHI = MOD - 1

e = 1
N = int(input())
A = map(int, input().split())
for a in A:
    e = e * a % (2 * PHI)
if e == 0:
    e += 2 * PHI
num = pow(2, e - 1, 3 * MOD)
num -= pow(-1, e - 1, 3 * MOD)
num //= 3
num %= MOD
den = pow(2, e - 1, MOD)
print(f"{num}/{den}")