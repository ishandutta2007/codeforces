# mind blown...

import sys
import random

def main():
	TEST = False
	n, B = [int(x) for x in input().split(' ')]

	queries = [0]
	if TEST:
		f = [random.randint(0, 2 ** min(B, i % 10) - 1) for i in range(n)]

	def ask(x, A):
		if x >= 0:
			if A == 0:
				return True
			A -= 1
		queries[0] += 1
		s = ""
		for i in range(B-1, -1, -1):
			s += str(1 & (A >> i))

		sys.stdout.write(f"{x+1} {s}\n")
		sys.stdout.flush()
		if x == -1:
			return
		if TEST:
			return f[x] > A
		s = input()
		if s == "yes":
			return True
		elif s == "no":
			return False
		else:
			assert False
	s = 0
	INF = 2 ** (B+1)

	upper_bounds = [2 ** B for i in range(n)]
	cur = 0
	while upper_bounds != [INF] * n:
		if upper_bounds[cur] != INF:
			e = min(upper_bounds)
			m = (s + e) // 2
			if ask(cur, m):
				s = m
				if ask(cur, e):
					s = e
				else:
					upper_bounds[cur] = e
			else:
				upper_bounds[cur] = m
			upper_bounds = [a if a > s+1 else INF for a in upper_bounds]
		cur = (cur + 1) % n
	ask(-1, s)

	if TEST:
		sys.stderr.write(f"{s} {f}\n")
		assert(s == max(f))
		sys.stderr.write(f"{queries}\n")

main()