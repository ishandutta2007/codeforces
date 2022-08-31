R=lambda:map(int,raw_input().split())
n,m=R()
a=[0]+R()
p=0
for _ in range(m):
	q=R()
	if q[0]==1:a[q[1]]=q[2]-p
	elif q[0]==2:p+=q[1]
	else:print a[q[1]]+p