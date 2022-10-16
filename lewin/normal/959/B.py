n,k,m = map(int, raw_input().split())
words = raw_input().split()
widx = {}
s = 0
for word in words:
	widx[word] = s
	s += 1
costs = map(int, raw_input().split())
gidx = [-1 for __ in xrange(n)]
mincost = [10000000000 for __ in xrange(k)]
for i in xrange(k):
	w = map(int, raw_input().split())
	mc = 10000000000
	for e in w[1:]:
		gidx[e-1] = i
		mc = min(mc, costs[e-1])
	mincost[i] = mc

tr = raw_input().split()
ans = 0
for t in tr:
	ans += mincost[gidx[widx[t]]]
print ans