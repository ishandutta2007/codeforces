MaxN=110010
u=[0 for i in range(MaxN)]
u[0]=u[1]=1
for i in range(2,MaxN):
    if u[i]:
        continue
    j=i*2
    while j<MaxN:
        u[j]=1
        j+=i
i=MaxN-2
while i>0:
    u[i]=u[i+1] if u[i] else i
    i-=1
n,m=map(int,raw_input().split())
a=[map(int,raw_input().split()) for i in range(n)]
for i in range(n):
    for j in range(m):
        a[i][j]=u[a[i][j]]-a[i][j]
ans1=min(sum(a[i][j] for j in range(m)) for i in range(n))
ans2=min(sum(a[i][j] for i in range(n)) for j in range(m))
print min(ans1,ans2)