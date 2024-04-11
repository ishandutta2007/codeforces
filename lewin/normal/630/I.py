import sys
import math

f = sys.stdin

n = int(f.readline())

ans = 0
for begin in xrange(n-1):
	free = n-2
	ways = 4
	if begin > 0:
		free -= 1
		ways *= 3
	if begin < n-2:
		free -= 1
		ways *= 3
	while free > 0:
		free -= 1
		ways *= 4
	ans += ways
print ans