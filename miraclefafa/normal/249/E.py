def sumr(x,y):
	if x>=y: return (4*x+3*x*x+2*x*x*x-y-3*x*y+y*y*y)*y/6
	else: return (-x+x*x*x+4*y+3*x*y-3*y*y+2*y*y*y)*x/6
T=input()
for i in xrange(T):
	a,b,c,d=map(int,raw_input().split())
	ret=sumr(c,d)-sumr(a-1,d)-sumr(c,b-1)+sumr(a-1,b-1)
	if ret<10**10: print ret
	else: print "...%010d" %(ret%(10**10))