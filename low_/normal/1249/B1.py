q=int(input())
for qq in range(q):
    n=int(input())
    P=list(map(int, input().split()))
    P.insert(0, 0)
    root=list(range(n+1))
    cnt=list(range(n+1))
    for i in range(0, n+1): 
        cnt[i]=1
    
    def getroot(u):
        if (root[u]==u): 
            return u
        else:
            root[u]=getroot(root[u])
            return root[u]
    
    for i in range(1, n+1):
        cnt[getroot(i)]=cnt[getroot(i)]+cnt[getroot(P[i])]
        root[getroot(P[i])]=getroot(i)
    #print(root)
    for i in range(1, n+1):
        print(cnt[getroot(i)]//2, end=" ")
    print()