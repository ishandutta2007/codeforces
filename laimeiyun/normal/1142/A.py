from fractions import gcd

n, k = map(int, raw_input().split())
a, b = map(int, raw_input().split())

m1 = 1
m2 = n * k

def solve(x):
	global m1, m2
	x %= k
	if x < 0:
		x += k
	for i in xrange(n):
		d = gcd(i * k + x, n * k)
		m1=max(m1, d)
		m2=min(m2, d)

solve(a + b)
solve(a - b)
solve(b - a)
solve(- a - b)

print n * k / m1, n * k / m2