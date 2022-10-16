import sys

def f(n,k,x):
	e = n/x
	if e < k*(k+1)/2:
		return
	print " ".join(map(lambda y: str(x*y), range(1,k))), x*(e-(k*(k-1)/2))
	sys.exit(0)

n,k = map(int, raw_input().split())
for div in xrange(1,100001):
	if n % div == 0:
		f(n,k,n/div)
for div in xrange(100000, 0, -1):
	if n % div == 0:
		f(n,k,div)
print -1