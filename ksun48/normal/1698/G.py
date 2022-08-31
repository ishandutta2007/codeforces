import sys
from math import lcm
from collections import defaultdict

def solve(p):
	poly = int(p[::-1], 2)
	assert p[0] == '1' and p[-1] == '1'
	degree = len(p) - 1
	def reduce(a):
		while a.bit_length() > degree:
			b = a.bit_length() - degree - 1
			a ^= poly << b
		assert a < (1 << degree)
		return a

	def mul(a, b):
		a = reduce(a)
		b = reduce(b)
		val = 0
		for i in range(degree):
			if (a >> i) & 1:
				val ^= (b << i)
		for i in range(degree, -1, -1):
			if (val >> (degree + i)) & 1:
				val ^= poly << i
		return val
	
	def pow(a, k):
		res = 1
		while k:
			if k & 1:
				res = mul(res, a)
			k >>= 1
			a = mul(a, a)
		return res

	pfs = defaultdict(int)
	pfs[2] += degree
	for i in range(1, degree + 1):
		cur = 2 ** i - 1
		p = 2
		while p * p <= cur:
			while cur % p == 0:
				cur //= p
				pfs[p] += 1
			p += 1
		if cur > 1:
			pfs[cur] += 1
	order_multiple = 1
	for p in pfs:
		order_multiple *= p ** pfs[p]
	
	order = order_multiple
	x = reduce(1 << 1)
	for p in pfs:
		while order % p == 0 and pow(x, order // p) == 1:
			order //= p
	return order

s = input()
if '1' not in s:
	print(-1)
	sys.exit()

p = s.lstrip('0')
l0 = len(s) - len(p)
p = p.rstrip('0')

res = solve(p)
print(f"{1 + l0} {1 + l0 + res}")