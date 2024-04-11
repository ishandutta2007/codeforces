n,m = map(int, raw_input().split())

es = []
for __ in xrange(m):
	a,b,c = map(int, raw_input().split())
	es.append((c,a-1,b-1))

es = sorted(es)

par = [i for i in xrange(n)]
sz = [1 for i in xrange(n)]

def root(x):
	if x == par[x]:
		return x
	par[x] = root(par[x])
	return par[x]

def unite(a,b):
	x = root(a)
	y = root(b)

	if x == y:
		return False

	if sz[x] < sz[y]:
		x,y = y,x

	sz[x] += sz[y]
	par[y] = x
	return True

ans = 0
idx = 0
while idx < m:
	f = idx
	while f < m and es[f][0] == es[idx][0]:
		f += 1

	avail = 0
	for j in xrange(idx, f):
		if root(es[j][1]) != root(es[j][2]):
			avail += 1
	used = 0
	for j in xrange(idx,f):
		if unite(es[j][1], es[j][2]):
			used += 1

	ans += avail - used
	idx = f

print ans