q = int(raw_input())

def f(x):
	if x % 2 == 0:
		return x / 2
	else:
		return (x / 2) - x


for ___ in xrange(q):
	l,r = map(int, raw_input().split())
	l -= 1
	print f(r) - f(l)