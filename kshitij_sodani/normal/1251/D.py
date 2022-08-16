def check(mid):
    x=[]
    y=[]
    z=[]
    for i in it:
        if i[1]<mid:
            x.append(i)
        elif i[0]>=mid:
            y.append(i)
        else:
            z.append(i)
    co=sum([i[0] for i in x])
    co+=sum([i[0] for i in y])
    ll=len(y)
    m=0

   #if len(z)==0:
    #    return False
    ne=max(0,(n+1)//2-ll)
    if ne>len(z):
        return False
    j=0
    for i in z:
        if j<len(z)-ne:
            co+=i[0]
        else:
            co+=mid
        j+=1
    
    return co<=s
   
import sys
input=sys.stdin.readline
t=int(input())
for _ in range(t):
    n,s=map(int,input().split())
    it=[]
    for i in range(n):
        it.append(list(map(int,input().split())))
    it.sort()
    l=1
    r=max(it,key=lambda x:x[1])[1]+1
    while abs(l-r)>=2:
        mid=(l+r)//2
        st=check(mid)
        if st:
            l=mid
        else:
            r=mid
    ma=l
    for i in range(l,r+1):
        st=check(i)
        if st:
            ma=max(ma,i)
    print(ma)