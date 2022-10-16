t = int(raw_input())

f = [0]
for __ in xrange(100):
	f.append(f[-1] * 4 + 1)

p = [0]
for g in xrange(100):
	p.append(p[-1] + (pow(2,g+1)-1))

for __ in xrange(t):
	n,k = map(int, raw_input().split())
	if k == 1:
		print "YES", n-1
		continue

	if n < len(f) and k > f[n]:
		print "NO"
		continue
	on = n

	n = min(n, len(f))
	for j in xrange(n-1,-1,-1):
		if p[n-j] > k:
			continue

		other = pow(2, n-j)
		avail = (other - 1) * (other - 1) * f[j]
		if f[n-j] + avail >= k:
			print "YES", on - (n - j)
			break
	else:
		print "NO"