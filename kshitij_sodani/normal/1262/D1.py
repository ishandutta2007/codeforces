import sys
input=sys.stdin.readline
def s(i):
    if i==0:
        return 0
    tot=0
    while i>0:
        tot+=tree[i]
        i-=(i&-i)
    return tot
def u(i,jj):
    while i<=n:
        
        tree[i]+=jj
        i+=(i&-i)
       # print(i)

n=int(input())
tree=[0]*(n+1)
it=list(map(int,input().split()))
#ttt=it[:]
ss={}
anss={}
it=[[i,j] for j,i in enumerate(it)]
for i in it:
    ss[i[1]]=i[0]
it.sort(reverse=True,key=lambda x:[x[0],-x[1]])
m=int(input())
ans=[]
mi=float("inf")
ii=-1
ans=[]
for i in range(n):
    if it[i][1]<mi:
        mi=it[i][1]
        ii=it[i][0]
    ans.append(ii)
q=[]
for i in range(m):
    k,pos=map(int,input().split())
    q.append([k,pos,i])
q.sort(key=lambda x:x[0])
q=[i+[0] for i in q]
ti=0
j=0
ans=[]
for i in q:
    if i[0]>ti:
        for k in range(ti+1,i[0]+1):
            u(it[k-1][1]+1,1)
            
        
        ti=i[0]
    #    print(tree)
    low=1
    high=n
   # print(i,"q")
    while low<high-2:
        mid=(low+high)//2
        x=s(mid)
    #    print(mid,x)
        if x<i[1]:
            low=mid+1
        elif x==i[1]:
            high=mid
        else:
            high=mid-1
    for ii in range(low,high+1):
        if s(ii)==i[1]:
            low=ii
            break
  #  print(low,"i",s(1))      
    q[j][3]=ss[low-1]#it[low-1][1]
    anss[q[j][2]]=ss[low-1]
    
    j+=1
q.sort(key=lambda x:x[2])
for i in range(m):
    print(anss[i])