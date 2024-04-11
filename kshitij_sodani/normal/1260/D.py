import sys
input=sys.stdin.readline
def inter(a,b):
    if b[0]<=a[1]:
        return 1
    return 0
def check(le):
    if le==0:
        return 1
    mi=it[le-1]
  #  print(mi)
    tr=[i[:2] for i in aaa if i[2]>mi]
    if tr==[]:
        return 1
    aa=[tr[0][:]]
  #  print(le,tr)
    for i in range(1,len(tr)):
        if inter(aa[-1],tr[i]):
            aa[-1][1]=max(aa[-1][1],tr[i][1])
        else:
            aa.append(tr[i][:])
    tt=0
    a=0
   # print(aa)
    for i in range(len(aa)):
        tt+=(aa[i][0]-1-a)
        a=aa[i][0]-1
        tt+=3*(aa[i][1]-aa[i][0]+1)
        a=aa[i][1]
    tt+=(n+1)-a
  #  print(le,tt)
  #  print()
    return tt<=t
    
m,n,k,t=map(int,input().split())
it=list(map(int,input().split()))
it.sort(reverse=True)
aaa=[]
for i in range(k):
    l,r,d=map(int,input().split())
    aaa.append([l,r,d])
aaa.sort()
low=0
high=m
while low<high-1:
    mid=(low+high)//2
    a=check(mid)
    if a:
        low=mid
    else:
        high=mid-1
for i in range(high,low-1,-1):
    if check(i):
        ans=i
        break
print(ans)