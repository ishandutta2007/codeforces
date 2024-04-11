import sys
input=sys.stdin.readline
t=int(input())
def find(no):
    global par
    if par[no]==no:
        return no
    par[no]=find(par[no])
    return par[no]
for _ in range(t):
    n,k=map(int,input().split())
    s=[ord(i)-97 for i in input()]
    
    par=[i for i in range(n)]
    vis=[0 for i in range(n)]
    for i in range(k):
        for j in range(i,n,k):
        
            vis[j]=1
            x=n-j-1
            aa=find(x)
            bb=find(j)
            par[bb]=aa
            if(j>i):
                aa=find(j-k)
                bb=find(j)
                par[bb]=aa
    tot=n
    aa=set(par)
    co=[[0 for i in range(26)] for j in range(n)]
   # print(par)
    for i in range(n):
        co[par[i]][s[i]]+=1
    tot-=sum([max(i) for i in co])
    print(tot)