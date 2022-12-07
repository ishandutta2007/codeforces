k=int(raw_input());
l=int(raw_input());
m=int(raw_input());
n=int(raw_input());
d=int(raw_input());
a=[0]*100010;
for i in range(k,d+1,k):
	a[i]=1;
for i in range(l,d+1,l):
	a[i]=1;
for i in range(m,d+1,m):
	a[i]=1;
for i in range(n,d+1,n):
	a[i]=1;
ans=0;
for i in range(1,d+1):
	if a[i]==1:
		ans=ans+1;
print ans;