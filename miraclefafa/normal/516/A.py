s=raw_input()
s=raw_input()
f=[1]
ans=[]
for i in xrange(1,10): f.append(f[i-1]*i)
r=1
for c in s: r=r*f[ord(c)-ord('0')]
def gao(x):
	global r
	while r%f[x]==0:
		r/=f[x]
		ans.append(x)
gao(7)
gao(5)
gao(3)
gao(2)
print "".join(map(str,ans))