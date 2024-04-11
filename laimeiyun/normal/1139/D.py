import sys

P = 10 ** 9 + 7

m = input()

mu = [0 for i in range(m + 1)]

mu[1] = 1

for i in range(1, m + 1):
	if mu[i] == 0:
		continue
	for j in range(i + i, m + 1, i):
		mu[j] -= mu[i]

ans = 1

for i in range(2, m + 1):
	if mu[i] ==0:
		continue

	ans = ans - mu[i] * (m / i) * pow(m - m / i, P - 2, P)

ans = (ans % P + P) % P

print ans