def dfs(no,par=-1,c=0):
    global adj,vis,col,st
    col[no]=c
    
    for i in adj[no]:
        if vis[i]==1:
            
            if col[i]==col[no]:
                st=0
                continue
            else:
                continue
        
        vis[i]=1
        
        dfs(i,no,1-c)
n=int(input())
s=list(input())

s=[ord(i)-97 for i in s]
if sorted(s)==s:
    print("YES")
    print("0"*n)
else:
    st=1
    adj=[[] for i in range(n)]
    for i in range(n):
        for j in range(i):
            if s[i]<s[j]:
                adj[i].append(j)
                adj[j].append(i)
    col=[-1 for i in range(n)]
    vis=[0 for i in range(n)]
    st=1
    for i in range(n):
        if vis[i]==0:
            vis[i]=1
            dfs(i)
          #  print(vis)
    if st:
        col=[str(i) for i in col]
        print("YES")
        print(''.join(col))
    else:
        print("NO")