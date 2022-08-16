#list(map(int,input().split()))
from bisect import *
n,m,k=map(int,input().split())
aa=list(map(int,input().split()))
bb=list(map(int,input().split()))
ma=int(k**0.5)
co=0
pre=[-1 for i in range(n)]
pre2=[-1 for i in range(m)]
cc=[]
for i in range(n):
    if aa[i]==1:
        co+=1
        pre[i]=co
        cc.append(co)
    else:
        co=0
co=0
dd=[]
for i in range(m):
    if bb[i]==1:
        co+=1
        pre2[i]=co
        dd.append(co)
    else:
        co=0
cc.sort()
dd.sort()
tot=0
for i in range(1,ma+1):
    if(k%i==0):
        indd=len(cc)-bisect_left(cc,i)
        x=k//i
        ind=len(dd)-bisect_left(dd,x)
        tot+=indd*ind
        
        if(i*i==k):
            continue
        indd=len(dd)-bisect_left(dd,i)
        ind=len(cc)-bisect_left(cc,x)
        tot+=indd*ind
print(tot)