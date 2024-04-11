n=input()
ans=[]
def digs(u):
	v=str(u)
	ret=0
	for p in v:
		ret+=ord(p)-ord('0')
	return ret
for i in xrange(1,200):
	if n>=i and digs(n-i)==i:
		ans.append(n-i)
ans.sort()
print len(ans)
for p in ans:
	print p