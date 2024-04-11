import sys
import random
import math
random.seed()

n = int(input())
divs = {n}

for opi in range(50):
	x = random.randint(1, n-1)
	a = 0
	b = 0
	if math.gcd(x, n) == 1:
		xx = (x*x) % n;
		print("sqrt", end=" ")
		print(xx)
		sys.stdout.flush()
		y = int(input())

		a = x + y #\neq 0 (mod n)
		if a == n:
			continue

		b = x - y #\neq 0 (mod n)
		if b == 0:
			continue
		if b < 0:
			b = -b
	
		a = math.gcd(a, n)
		b = math.gcd(b, n)
		c = math.gcd(a, b)
		a //= c
	else:
		a = math.gcd(x, n)
		b = n // a

	assert a * b == n
	assert a != 1
	assert b != 1

	nxtdivs = set()
	for v in divs:
		va = math.gcd(a, v)
		vb = math.gcd(b, v)
		if va != 1:
			nxtdivs.add(va)
		if vb != 1:
			nxtdivs.add(vb)
	divs = nxtdivs

print("!", end=" ")
print(len(divs), end = " ")
for v in divs:
	print(v, end = " ")
print()