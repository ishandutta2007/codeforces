N=list(map(int,input().split()))
Ans=sum(N)
for n in N:
    c=N.count(n)
    if c > 1:
        Ans=min(Ans,sum(N) - min(c,3)*n)
print(Ans)