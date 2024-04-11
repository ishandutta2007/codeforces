
import sys
input=sys.stdin.readline
sys.setrecursionlimit(10**8)#from collections import dequeue
import bisect as bs
def floyd_warshall(n, edges):
    dist = [[0 if i == j else float("inf") for i in range(n)] for j in range(n)]
 
    for i in range(n):
        for j in range(n):
            if A[i][j]:
                dist[i][j] = 1
 
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if dist[i][k] + dist[k][j] < dist[i][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]
    return dist
n=int(input())
adj=[set() for i in range(n)]
A=[0]*n
for i in range(n):
    k=0
    s=list(map(int,list(input())[:-1]))
    A[i]=s
    for j in s:
        if j==1:
            adj[i].add(k)
        k+=1
m=int(input())
it=list(map(int,input().split()))
it=[i-1 for i in it]
ss={}
j=0
for i in it:
    try:
        ss[i].append(j)
    except:
        ss[i]=[j]
    j+=1

p=[it[0]]
dp=[10**6+5]*m
sh={}
pp={}
sh=floyd_warshall(n,A)
##def dfs(no,co,vis):
##    global c
##    for i in adj[no]:
##        if vis[i]==1:
##            continue
##            if co+1<sh[(c,i)]:
##                sh[(c,i)]=co+1
##                dfs(i,co+1,vis)
##            if co+1==sh[(c,i)]:
##                
##                dfs(i,co+1,vis)
##        else:
##            vis[i]=1
##            try:
##                x=sh[(c,i)]
##                if x>co+1:
##                    sh[(c,i)]=co+1
##                    dfs(i,co+1,vis)
##                elif co+1==sh[(c,i)]:
##                    dfs(i,co+1,vis)
##            except:
##                sh[(c,i)]=co+1
##                dfs(i,co+1,vis)
##            vis[i]=0
##        
##for c in range(n):
##    vis=[0]*n
##    vis[c]=1
##    sh[(c,c)]=1
##    dfs(c,1,vis)
p=[it[0]+1]
ind=1
while ind<m:
    d=2
    while ind<m and sh[p[-1]-1][it[ind]]+1>=d:
        ind+=1
        d+=1
    p.append(it[ind-1]+1)
    d=1
print(len(p))
print(*p)