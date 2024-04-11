import sys
import random
import math


pfs = []

pfset = set()

def factor(n):
	# print("factoring " + str(n))
	for z in range(60):
		x = random.randint(0, n-1)
		r = (x * x) % n;
		query = "sqrt " + str(r)
		print(query)
		sys.stdout.flush()

		y = int(input())

		g = math.gcd(x+y, n)
		if g == 1 or g == n:
			continue
		pfs.append(g)
		pfs.append(n // g)

def get_factors(n):
	for x in pfs:
		a = math.gcd(x, n)
		if a == 1 or a == n:
			continue
		get_factors(a)
		get_factors(n//a)
		return
	pfset.add(n)


def solve(n):
	factor(n)
	get_factors(n)

	ans = "!"
	ans += " " + str(len(pfset))
	for x in pfset:
		ans += " " + str(x)
	print(ans)
	sys.stdout.flush()

n = int(input())
solve(n)