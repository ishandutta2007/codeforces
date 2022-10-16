import sys
import random
from fractions import gcd

f = sys.stdin
n = int(f.readline())
x,y = zip(*[map(int, f.readline().split()) for i in range(n)])
st = random.randint(0, n-1)
dist = [(x[i]-x[st])*(x[i]-x[st])+(y[i]-y[st])*(y[i]-y[st]) for i in range(n)]

def getSlope(x1,y1):
	g = gcd(abs(x1),abs(y1))
	x1,y1 = x1/g,y1/g
	if x1 < 0 or (x1 == 0 and y1 < 0):
		x1,y1 = -x1,-y1
	return (x1,y1)

s = {}
for i in xrange(n):
	if i == st: continue
	slope = getSlope(x[i] - x[st], y[i] - y[st])
	if slope not in s or dist[i] < dist[s[slope]]:
		s[slope] = i

lst = sorted(s.values(), key=lambda x: dist[x])
print st+1, lst[0]+1, lst[1]+1