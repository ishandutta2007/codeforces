t=int(raw_input())

for _ in xrange(t):
	h,c,t=map(int,raw_input().split())
	if 2*t<=h+c:
		print 2
	elif t>=h:
		print 1
	else:
		k1=(h-t)/(2*t-h-c)
		f1=[(k1+1)*h+k1*c,2*k1+1]
		f2=[(k1+2)*h+(k1+1)*c,2*k1+3]
		s=[f1[0]*f2[1]+f1[1]*f2[0],f1[1]*f2[1]]
		if s[0]<=2*t*s[1]:
			print 2*k1+1
		else:
			print 2*k1+3