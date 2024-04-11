from heapq import *
def bfs(a,b,adj):
    global n,mi
    s=[[0,a]]
    vis=[0]*n
    while s:
        c=heappop(s)
        for i in adj[c[1]]:
            if vis[i]:
                continue
            if i==b:
                mi=min(mi,c[0]+2)
                return 
            else:
                heappush(s,[c[0]+1,i])
                vis[i]=True
                
            
n=int(input())
it=list(map(int,input().split()))
it=[i for i in it if i!=0]
n=len(it)
if len(it)>124:
    print(3)
else:
    adj=[set() for i in range(n)]
    ss=[list(map(int,list(bin(i)[2:]))) for i in it]
    ma=-1
    ed=[]
    for i in range(len(ss)-1):
        for j in range(i+1,len(ss)):
           # if it[i]==it[j]:
            #    continue
            for k,l in zip(ss[i][-1::-1],ss[j][-1::-1]):
                if k==1 and k==l:
                    adj[i].add(j)
                    adj[j].add(i)
                    ed.append([i,j])
                    break
    mi=10**10
    for i in ed:
        adj[i[0]].remove(i[1])
        adj[i[1]].remove(i[0])
        bfs(i[0],i[1],adj)
        adj[i[0]].add(i[1])
        adj[i[1]].add(i[0])

    if mi==10**10:
        print(-1)
    else:
        print(mi)