q=int(input())
for i in range(q):
    n,k=map(int,input().split())
    it=list(map(int,input().split()))
    ti=[i+k for i in it]
    st=False
    s=min(it)
    for i in it:
        if i-k>s+k:
            st=True
            break
    if st:
        print(-1)
    else:
        print(min(ti))