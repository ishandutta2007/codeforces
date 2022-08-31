n,t=map(int,raw_input().split())
a=[0]+map(int,raw_input().split())
for i in range(1,n+1):
    a[i]+=a[i-1]
j=1
ans=0
for i in range(1,n+1):
    while j<=n:
        if a[j]-a[i-1]>t:
            break
        j+=1
    ans=max(ans,j-i)
print ans