


import sys
input=sys.stdin.readline






n,a,b,k=map(int,input().split())
it=list(map(int,input().split()))
#it=[ for i in it]
co=0
aa=[]
for i in range(n):
    x=it[i]%(a+b)
    if x<=a and x>0:
        co+=1
        continue
    else:
        it[i]%=(a+b)
        if it[i]==0:
            it[i]+=a+b
        it[i]-=a
        aa.append((it[i])//a)
        if it[i]%a>0:
            aa[-1]+=1
            
aa.sort()
for i in aa:
    if i<=k:
        co+=1
        k-=i
print(co)