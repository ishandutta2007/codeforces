n,k=map(int,input().split())
it=list(map(int,input().split()))
a=[[] for i in range(n)]
for i in range(n):
    j=it[i]
    a[i]=[j]
    while True:
        j=j//2
        a[i].append(j)
        if j==0:
            break
ss={}
for i in a:
    for j in i:
        try:
            ss[j]+=1
        except:
            ss[j]=1
mi=10**10
for i in ss:
    if ss[i]>=k:
        l=[-1]*n
        j=0
        for ii in a:
            try:
                l[j]=ii.index(i)
            except:
                pass
            j+=1
        l=[i for i in l if i!=-1]
        l.sort()
        l=l[:k]
     #   if sum(l)<mi:
      #      print(l,i)
        mi=min(mi,sum(l))
print(mi)