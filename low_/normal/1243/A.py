k = int(input())
while k>0:
    k = k-1
    n = int(input())
    A = list(map(int, input().split()))
    A.sort(reverse=True)
    p1=0
    p2=0
    curMin=A[0]
    ans=1
    while p2<n:
        curMin=min(curMin, A[p2])
        while (p2-p1+1>curMin): 
            p1=p1+1
        ans=max(ans, p2-p1+1)
        p2=p2+1
    print(ans)