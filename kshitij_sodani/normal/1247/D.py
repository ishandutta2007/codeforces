import sys
input=sys.stdin.readline
n,k=map(int,input().split())
it=list(map(int,input().split()))
ss=[1]
ma=10**10
a=2
while True:
    x=a**k
    if x>ma:
        break
    ss.append(x)
    a+=1
p=[]
ind=2
vis=[0]*(10**5+5)
p=[0]*(10**5+5)
while ind<len(vis):
    if vis[ind-1]==0:
        vis[ind-1]=1
        p[ind-1]=1
        vis[ind-1::ind]=[1]*len(vis[ind-1::ind])
    ind+=1
ind=2
fact=[[] for i in range(10**5+5)]
em={}
for i in range(1,len(p)):
    if p[i]==1:
        diff=i+1
        while diff<10**5+5:
            for j in range(diff,10**5+5,diff):
                fact[j-1].append(i+1)
            diff=diff*(i+1)
sp=[0 for i in range(10**5+5)]
tot=0
ma=10**5+5
till={}
ma=0
co=0
coo=0
for i in range(n):
##    if it[i]==1:
##        co+=1
##        tot+=coo
##        print(tot)
##        continue
    ss={}
    for j in fact[it[i]-1]:
        try:
            ss[j]+=1
        except:
            ss[j]=1
    
    aa=[]
    bb=[]
    st=False
    for ii in ss:
        if ss[ii]%k==0:
            continue
        st=True
        bb.append((ii,ss[ii]%k))
        aa.append((ii,k-ss[ii]%k))
       
        
    aa.sort(key=lambda x:x[0])
    bb.sort(key=lambda x:x[0])
##    if st==False:
##        tot+=co
##        print(tot)
##        tot+=coo
##        coo+=1
##        continue
    try:
        x=till[tuple(aa)]
        tot+=x
    except:
        pass
    try:
        till[tuple(bb)]+=1
    except:
        till[tuple(bb)]=1
   # print(aa,bb)
  #  print(tot)
print(tot)