import sys
sys.setrecursionlimit(10**9)
def dfs(a,pre=-1,par=None):
    global aa
    for i in adj[a]:
      #  print(i,pre,a,par)
        if i==par:
            continue
        if pre==-1:
            dfs(i,it[i],a)
        elif pre!=it[i]:
            aa=True
            return ''
        else:
            dfs(i,it[i],a)
            
n=int(input())
ed=[]
adj=[[] for i in range(n)]

for _ in range(n-1):
    a,b=map(int,input().split())
    ed.append([a-1,b-1])
    adj[a-1].append(b-1)
    adj[b-1].append(a-1)
it=list(map(int,input().split()))
st=False
for i in ed:
    if it[i[0]]!=it[i[1]]:
        st=True
        e=i
        break
if not(st):
    print("YES")
    print(1)
else:
    ans=True
    aa=False
    dfs(e[0])
   # print(aa)
    if aa==False:
        print("YES",e[0]+1,sep="\n")
    else:
        aa=False
        dfs(e[1])
        if aa==False:
            print("YES")
            print(e[1]+1)
        else:
            print("NO")