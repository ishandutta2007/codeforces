p=raw_input()
n=input()
q=[]
for i in xrange(n):
	x=raw_input()
	q.append(x)
for i in xrange(n):
	for j in xrange(n):
		if p in q[i]+q[j]:
			print "YES"
			exit()
print "NO"