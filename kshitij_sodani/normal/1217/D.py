import sys
sys.setrecursionlimit(10**9)
def dfs(a):
    global adj,vis,st
    j=0
    vis[a]=1
    for i in adj[a][:]:
        if vis[i[0]]==0:
            dfs(i[0])
            adj[a][j][1]=1
        elif vis[i[0]]==2:
            adj[a][j][1]=1
        else:
            st=2
            adj[a][j][1]=2
        j+=1
    vis[a]=2
 
n,m=map(int,input().split())
it=[]
adj=[[] for i in range(n)]
#print(adj)
for _ in range(m):
    a,b=map(int,input().split())
    adj[a-1].append([b-1,1,_])
    #print(adj)
vis=[0]*n
st=1
for ii in range(n):
    if vis[ii]==0:
        dfs(ii)
print(st)
ans=[0]*m
for i in range(n):
    for j in adj[i]:
      #  print(j[2],j[1])
        ans[j[2]]=j[1]
print(*ans)