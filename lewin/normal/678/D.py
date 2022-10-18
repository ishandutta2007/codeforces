import sys

def r():
	return sys.stdin.readline()

mod = 1000000007

def q(n,a,b):
	if n == 0:
		return 1,0
	if n == 1:
		return a,b
	if n % 2 == 1:
		xa,xb = q(n-1,a,b)
		return a*xa % mod, (a*xb + b) % mod
	else:
		xa,xb = q(n/2,a,b)
		return xa*xa % mod, (xa*xb + xb) % mod

a,b,n,x = map(int, r().split())

xa,xb = q(n,a,b)
print (x*xa+xb) % mod