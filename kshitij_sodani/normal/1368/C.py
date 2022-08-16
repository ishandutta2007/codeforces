n=int(input())
ans=[]
ans.append([0,0])
cur=[[0,1],[1,1],[1,0]]
for i in range(n+1):
    for j in cur:
        ans.append(j)
    cur=[[i[0]+1,i[1]+1] for i in cur]
##ans=[]
##for i in range(1,2*n):
##    ans.append([0,i])
##for i in range(2*n+1):
##    if(i%2==1):
##        ans.append([1,i])
##for i in range(2*n+1):
##    ans.append([2,i])
##for i in range(2*n+1):
##    if(i%2==1):
##        ans.append([3,i])
##for i in range(1,2*n):
##    ans.append([4,i])
##
print(len(ans))
for i in ans:
    print(i[1],i[0])
##grid=[[0 for i in range(10)] for j in range(10)]
##for i in ans:
##    grid[i[0]][i[1]]=1
##for i in grid:
##    print(*i)