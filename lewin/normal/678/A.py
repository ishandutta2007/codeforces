import sys

def r():
	return sys.stdin.readline()

n, k = map(int, r().split())

m = n % k

print n + (k-m)