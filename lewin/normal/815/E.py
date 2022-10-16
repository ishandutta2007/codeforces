f = {}
def c(n, p):
	k = (n, p)
	if k in f: return f[k]

	d = (n-1)/2
	f[k] = d >= p and (1 + c(d, p) + c(n-d-1, p))

	return f[k]

def w(l, r, k):
	m = (l+r)/2

	if k == 0: return m

	x = c(m-l, p)
	y = c(r-m, p+1)

	return w(l, m-1, k-y-1) if x+y>=k else w(m+1, r, k-x-1)

n,k = map(int, raw_input().split())

if k == 1: print 1
elif k == 2: print n
else:
	p, q = 0, n
	while p < q:
		m = (p+q+1) / 2
		if c(n-2, m) >= k-2: p = m
		else: q = m-1
	print w(2, n-1, k-3)