import sys
input=sys.stdin.readline
t=int(input())
for _ in range(t):
    n,s,k=map(int,input().split())
    it=list(map(int,input().split()))
    it=set(it)
    
    for i in range(n):
        if s+i<=n and s+i not in it:
            ans=i
            break
        if s-i>=1 and s-i not in it:
            ans=i
            break
    print(ans)