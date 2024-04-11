q=int(input())
for _ in range(q):
    n=int(input())
    it=list(map(int,input().split()))
    it.sort()
    st=1
    for i in range(n-1):
        if abs(it[i]-it[i+1])==1:
            st=2
    print(st)