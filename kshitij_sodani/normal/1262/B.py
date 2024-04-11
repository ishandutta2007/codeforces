t=int(input())
for i in range(t):
    n=int(input())
    it=list(map(int,input().split()))
    arr=[0]*n
    arr[0]=it[0]
    ans=0
    vis=[0]*n
    vis[arr[0]-1]=1
    ind=0
    if vis[0]==1:
        ind+=1
    for i in range(1,n):
        while ind<n:
            if vis[ind]==0:
                break
            ind+=1
        if it[i]>it[i-1]:
            arr[i]=it[i]
            vis[it[i]-1]=1
        else:
            arr[i]=ind+1
            if arr[i]>it[i]:
                ans=-1
            vis[ind]=1
    if ans==-1:
        print(-1)
    else:
        print(*arr)