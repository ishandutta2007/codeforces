t=int(input())
for _ in range(t):
    n=int(input())
    it=list(map(int,input().split()))
    ind=n
    a=it.count(1)
    b=2*n-a
    if b<a:
        it=[3-i for i in it]
    a,b=sorted([a,b])
    diff=a-b
    aa=[0 for i in range(n)]
    if it[n-1]==2:
        aa[n-1]=-1
    else:
        aa[n-1]=1
    for i in range(n-2,-1,-1):
        if it[i]==2:
            aa[i]=aa[i+1]-1
        else:
            aa[i]=aa[i+1]+1

    bb=[0 for i in range(n)]
    if it[n]==2:
        bb[0]=-1
    else:
        bb[0]=1
    for i in range(1,n):
        if it[i+n]==2:
            bb[i]=bb[i-1]-1
        else:
            bb[i]=bb[i-1]+1
    ss={}
    tt={}
    for i in range(n):
        try:
            ss[aa[i]]=max(ss[aa[i]],i)
        except:
            ss[aa[i]]=i
    for i in range(n):
        try:
            tt[bb[i]]=min(tt[bb[i]],i+n)
        except:
            tt[bb[i]]=i+n
    mi=2*n
    if diff==0:
        mi=0
    for i in range(n):
        if aa[i]==diff:
            mi=min(mi,n-i)
            continue
        else:
            co=diff-aa[i]
          #  print(co)
            try:
                x=tt[co]
                do=x-i+1
                mi=min(mi,do)
            except:
                continue
    for i in range(n):
        if bb[i]==diff:
            mi=min(mi,i+1)
    print(mi)