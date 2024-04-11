s=input()
def floyd_warshall(n, A):
    dist = [[float("inf") for i in range(n)] for j in range(n)]
 
    for i in range(n):
        for j in range(n):
            if A[i][j]:
                dist[i][j] = A[i][j]
 
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if dist[i][k] + dist[k][j] < dist[i][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]
    return dist
cp={}
for ii in range(len(s)-1):
    p=int(s[ii])
    q=int(s[ii+1])
    try:
        cp[(p,q)]+=1
    except:
        cp[(p,q)]=1

for i in range(10):
    res=[]
    for j in range(10):
        adj=[[] for i in range(10)]
      #  adj=[[0]*10 for i in range(10)]
        adj=[[0]*10 for i in range(10)]
        for ii in range(10):
            adj[ii][ii]=0
                
            adj[ii][(ii+i)%10]=1
    
            adj[ii][(ii+j)%10]=1
        
        
        dist=floyd_warshall(10,adj)
     #   if i==1 and j==1:
      #      print(dist)
        tot=0
        tot=0
        st=True
        for ii in cp:
            ii=tuple(ii)
            p=ii[0]
            q=ii[1]
                #continue
            x=dist[p][q]

            if x==float("inf"):
                st=False
                break                
            tot+=(x-1)*cp[ii]
        if not(st):
            res.append(-1)
        else:
            res.append(tot)
    print(*res)