from random import *

def query(a, b):
	print("? %d %d" % (len(a), len(b)))
	print(*a)
	print(*b)
	return -1 if input() == "SECOND" else 1

def solve(n, k):
	for i in range(28):
		x = randint(2, n)
		if query([1], [x]) < 0: return 1
	a = [1]
	while True:
		b = list(range(len(a)+1, min(2*len(a), n)+1))
		if query(b, a[:len(b)]) < 0: break
		a += b
	while len(b) > 1:
		m = len(b)//2
		b = b[:m] if query(b[:m], a[:m]) < 0 else b[m:]
	return b[0]

for _ in range(int(input())):
	n, k = map(int, input().split())
	print("! %d" % solve(n, k))