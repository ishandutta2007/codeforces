n,k=map(int,input().split())
aa=list(map(int,input().split()))
bb=list(map(int,input().split()))
ab="abcdefghijklmnopqrstuvwxyz"
#print(len(ab))
ss={}
j=0
it=[]
for i in aa:
    ss[i]=j
    j+=1
jj=0
for i in bb:
    ind=ss[i]
    j,ind=sorted([jj,ind])
    it.append([j,ind])
  #  print(i,jj,ind)
    jj+=1
    
it.sort()
do=1
ma=it[0][1]
res=[]
st=it[0][0]

for i in it[1:]:
    if i[0]<=ma:
        ma=max(ma,i[1])
        
    else:
        do+=1
        res.append([st,ma])
        st=i[0]
        ma=i[1]

    j+=1
if res==[]:
    res=[[0,n-1]]
else:
    if res[-1][1]!=n-1:
        res.append([res[-1][1]+1,n-1])
if len(res)<k:
    print("NO")
else:
    print("YES")
    if len(res)>k:
      #  print(res[:k-1])
       # print(res)
        res=res[:k-1]+[[res[k-1][0],n-1]]
    kk=-1
    res.sort()
    ll=[0]*n
    for i in res:
        kk+=1
        for j in range(i[0],i[1]+1):
            ll[aa[j]-1]=ab[kk]
    for i in ll:
        print(i,end="")
    print()