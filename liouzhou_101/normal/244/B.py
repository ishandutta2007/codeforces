def p(k):
	if 0<k<=n:s.add(k);k*=10;p(k+x);p(k+y)
n=input();s=set()
for x in range(10):
	for y in range(10):p(x)
print len(s)