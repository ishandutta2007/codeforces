from fractions import gcd

n, p, q = map(int, input().split())
lcm = p // gcd(p, q) * q
if p > q:
	p, q = q, p
full = n % lcm
if p <= full + 1:
	good = (n // lcm + 1) * p
else:
	good = n // lcm * p + full + 1

good -= 1
g = gcd(good, n)
print('{}/{}'.format(good // g, n // g))