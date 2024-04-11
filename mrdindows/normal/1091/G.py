import random, sys

def gcd(x, y):
	while y > 0:
		x, y = y, x % y
	return x

def sqrt(x):
	print('sqrt', x)
	sys.stdout.flush()
	sys.stdout.flush()
	return int(input())

def factorize(n, a):
	for i in range(len(a)):
		if a[i] == 0:
			continue
		x = gcd(a[i], n)
		if 1 < x < n:
			y = n // x
			return factorize(x, [z % x for z in a]) + factorize(y, [z % y for z in a])
	return [n]
	
n = int(input())
a = []
for k in range(99):
	x = random.getrandbits(1024) % n
	y = sqrt((x * x) % n)
	if y < 0:
		continue
	x = gcd(n, n + x - y)
	if x > 1 and x < n:
		a.append(x)

ans = set(factorize(n, a))
print('!', len(ans), *ans)
sys.stdout.flush()
sys.stdout.flush()