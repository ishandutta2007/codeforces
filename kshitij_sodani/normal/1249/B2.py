import sys
sys.setrecursionlimit(10**6)
def dfs(a,par=-1):
    global xx
    cpar=par
    if par==-1:
        cpar=a
    i=adj[a]
    if i in xx:
        return
    if i==cpar:
        return
        
    xx.add(i)
    dfs(i,cpar)
q=int(input())

for _ in range(q):
    n=int(input())
    it=list(map(int,input().split()))
    ans=[-1 for i in range(n)]
    ind=0
    while ind<n:
        while ind<n:
            if ans[ind]==-1:
                break
            ind+=1
        if ind==n:
            continue
        arr=[ind]
        if it[0]-1==ind:
            ans[ind]=1
        else:
            arr.append(it[ind]-1)
            while arr[0]!=arr[-1] and len(arr)<2*n:
                arr.append(it[arr[-1]]-1)
            for i in arr:
                ans[i]=len(arr)-1
    print(*ans)