n,m=map(int,input().split())
aa=list(map(int,input().split()))
bb=list(map(int,input().split()))
ss={}
for i in bb:
    try:
        ss[i]+=1
    except:
        ss[i]=1
mi=float("inf")
for i in range(n):
    
    x=(bb[i]-aa[0])%m
    cc=[(a+x)%m for a in aa]
    tt={}
    for i in cc:
        try:
            tt[i]+=1
        except:
            tt[i]=1
    if ss==tt:
        mi=min(mi,x)
print(mi)