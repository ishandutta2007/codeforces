t=int(input())
for _ in range(t):
    n=int(input())
    it=list(map(int,input().split()))
    it.sort()
    ans=1
    ma=0
    for i in range(n):
        ma=max(ma,it[i])
        if(ma<=i+1):
            ans=max(ans,i+2)
    print(ans)