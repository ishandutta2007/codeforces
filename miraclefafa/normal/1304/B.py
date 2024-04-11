n,m=map(int,raw_input().split())
s=[]
t=[]

for i in xrange(n):
	s.append(raw_input())
	t.append(s[i][::-1])
used=[0]*n
mid=""
l=""
r=""

for i in xrange(n):
	if s[i]==t[i]:
		if mid=="":
			mid=s[i]
	else:
		for j in xrange(n):
			if t[j]==s[i] and not used[j]:
				used[j]=1
				used[i]=1
				l=l+s[i]
				r=s[j]+r
print len(l+mid+r)
print l+mid+r