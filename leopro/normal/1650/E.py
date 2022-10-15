def check(z,pos,n,d):
    #print(len(z),n,pos)
    if(pos<=0):
        return min(z)
    if(pos>=n):
        return min(z)
    val=(z[pos-1]+z[pos]) 
    z[pos-1]=val 
    del z[pos] 
    ans=min(z) 
    sum=d
    for t in z:
        sum-=t 
    ma=sum
    for t in z:
        ma=max(ma,t//2) 
    return min(ans,ma)
t1=int(input())
input()
for cyc in range(t1):
    n,d=map(int,input().split())
    a=[int(x) for x in input().split()]
    if(cyc==(t1-1)):
        pass 
    else:
        input()
    a=[0]+a 
    z=[]
    for i in range(n):
        z.append(a[i+1]-a[i]) 
    pos=0 
    for j in range(n):
        if(z[j]<z[pos]): 
            pos=j 
    z1=z.copy() 
    sum=d
    for i in range(len(z1)-1):
        sum-=z[i]
    z1.pop() 
    z1.append(sum) 
    ans=min(z1)
    ans=max(ans,check(z.copy(),pos-1,n,d))
    ans=max(ans,check(z.copy(),pos+2,n,d))
    ans=max(ans,check(z.copy(),pos,n,d))
    ans=max(ans,check(z.copy(),pos+1,n,d))
    print(ans-1)