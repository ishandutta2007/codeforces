R=lambda:map(int,raw_input().split())
n,m,d=R()
a=[]
for i in range(n):a+=R()
x=a[0]%d
v=[]
for i in a:
	if i%d!=x:
		print -1
		exit()
	v+=[(i-x)/d]
v.sort()
print sum(abs(i-v[len(v)/2])for i in v)