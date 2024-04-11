def dfs(no,par=-1):
    global adj,vis
    for i in adj[no]:
        if vis[i]==0:
            vis[i]=1
            dfs(i,no)
import sys
input=sys.stdin.readline
sys.setrecursionlimit(10**9)
n=int(input())
it=[list(set(list(input().strip()))) for i in range(n)]

k=0

aa="abcdefghijklmnopqrstuvwxyz"
st={}
j=0
for i in aa:
    st[i]=j
    j+=1

k=0
tot=0
adj=[[] for i in range(26+n)]
k=0
for i in it:

    for j in i:
        #vis[st[j]]=1
        adj[n+st[j]].append(k)
        adj[k].append(n+st[j])
    k+=1
ind=0
vis=[0]*(n+26)
while ind<n+26:
    if vis[ind]==1:
        ind+=1
        continue
    if adj[ind]==[]:
        ind+=1
        continue
    tot+=1
    vis[ind]=1
  #  print(ind)
    dfs(ind)
  #  print(ind)
    ind+=1
    
print(tot)