import sys
input=sys.stdin.readline
t=int(input())
for _ in range(t):
    n,m=map(int,input().split())
    aa=list(map(int,input().split()))
    bb=list(map(int,input().split()))
    ans=0
    ind=0
    vis=[0 for i in range(n)]
    co=0
    for i in range(m):
        if vis[bb[i]-1]==1:
            ans+=1
            co-=1
            continue
        while ind<n:
            co+=1
            if aa[ind]==bb[i]:
                vis[aa[ind]-1]=1
                ind+=1
                break
            else:
                
                vis[aa[ind]-1]=1
                ind+=1
        co-=1
        ans+=co*2+1
       # print(ans,ind)
        
    print(ans)
   # print()