R,C = map(int,raw_input().split())
A = [raw_input() for i in xrange(R)]
ans = 0; R_ = set()
for i in xrange(R):
	if A[i].find('S') < 0:
		R_.add(i)
		ans += C
for i in xrange(C):
	s = ''.join([A[j][i] for j in xrange(R)])
	if s.find('S') < 0:
		for j in xrange(R):
			if not j in R_:
				ans += 1
print ans