a=[0]*10
k=input()
c=0
s="codeforces"
while reduce(lambda x,y:x*y,a)<k:
	a[c%10]+=1
	c+=1
t=""

for i in xrange(10):
	t+=s[i]*a[i]
print t