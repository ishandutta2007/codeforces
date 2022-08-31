n,k=map(int,input().split())
it=list(map(int,input().split()))
a=[[] for i in range(n)]
ss={}
for i in range(n):
    j=it[i]
    a[i]=[j]
    try:
        ss[j].append(0)
    except:
        ss[j]=[0]
    st=0
    while True:
        st+=1
        j=j//2
        try:
            ss[j].append(st)
        except:
            ss[j]=[st]
        a[i].append(j)
        if j==0:
            break
tt=ss.copy()
mi=10**10
for i in ss:
    if len(ss[i])>=k:
        tt[i].sort()
        mi=min(mi,sum(tt[i][:k]))
print(mi)