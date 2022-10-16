n = int(raw_input())
r = map(int,raw_input().split())

ans=0
for i in xrange(n):
	tot = 0
	for j in xrange(i,n):
		tot += r[j]
		if tot > 100*(j-i+1):
			ans = max(ans, j-i+1)
print ans