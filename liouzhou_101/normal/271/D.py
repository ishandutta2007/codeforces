s=raw_input()
t=raw_input()
k=input()
n=len(s)
d=[s[i:] for i in range(n)]
d.sort()
ans=0
pre=""
for x in d:
	h=0
	lp=len(pre)
	lx=len(x)
	while h<lp and h<lx:
		if pre[h]!=x[h]:
			break
		h+=1
	p=0
	for i in range(h):
		if i!=h and t[ord(x[i])-ord('a')]=='0':
			p+=1
	while h<lx:
		if t[ord(x[h])-ord('a')]=='0':
			p+=1
		if p>k:
			break
		ans+=1
		h+=1
	pre=x
print ans