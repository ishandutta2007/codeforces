q=int(input())
for _ in range(q):
    n=int(input())
    it=list(map(int,input().split()))
    cu=[i+1 for i in range(n)]
    ans=[10**9 for i in range(n)]
    j=1
    while 10**9 in ans:
        cc=cu[:]
        for i in range(n):
            cu[it[i]-1]=cc[i]
        for i in range(n):
            if cu[i]==i+1:
                ans[i]=min(ans[i],j)
        j+=1
    print(*ans)