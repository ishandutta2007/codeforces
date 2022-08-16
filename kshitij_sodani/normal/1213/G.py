import sys
sys.setrecursionlimit(10**9)
def find(a):
    if par[a]==a:
        return a
    par[a]=find(par[a])
    return par[a]
n,m=map(int,input().split())
ed=[]
par=[i for i in range(n)]
size=[1 for i in range(n)]
for _ in range(n-1):
    a,b,c=map(int,input().split())
    ed.append([a-1,b-1,c])
ed.sort(key=lambda x:x[2])
it=list(map(int,input().split()))
it=[[i,j,0] for j,i in enumerate(it)]
it.sort()
ind=0
tot=0
j=0
#print(it)
ss={}
for i in it[:]:
    while ind<n-1:
        if ed[ind][2]<=i[0]:
            a=find(ed[ind][0])
            b=find(ed[ind][1])
            if a!=b:
                tot+=size[a]*size[b]
              #  print(a,b,j,tot)
                if size[a]>=size[b]:

                    par[b]=a
                    size[a]+=size[b]
                    size[b]=0
                else:
                    par[a]=b
                    size[b]+=size[a]
                    size[a]=0
            ind+=1
            
        else:
            break
    it[j][2]=tot
    #ss[it[j][1]]=tot
    j+=1

it.sort(key=lambda x:x[1])
aa=[i[2] for i in it]

#for i in range(len(it)):
 #   print(ss[i],end=" ")
print(*aa)