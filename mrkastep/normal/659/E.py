a=input().split()
n=int(a[0])
m=int(a[1])

p = []
rnk = []

def init(s):
    global p
    global rnk
    for i in range(0,s):
        p.append(i)
    rnk = [1]*s

def fs(v):
    global p
    if p[v]==v:
        return v
    ans = fs(p[v])
    p[v]=ans
    return ans

def us(a,b):
    global p
    global rnk
    a=fs(a)
    b=fs(b)
    if a==b:
        rnk[a]+=1
        return
    if rnk[a]>rnk[b]:
        p[b]=a
        rnk[a]+=rnk[b]
    else:
        p[a]=b
        rnk[b]+=rnk[a]

init(n)

for i in range(0,m):
    e=input().split()
    us(int(e[0])-1,int(e[1])-1)
D = {}
for i in range(0,n):
    if D.get(fs(i))==None:
        D[fs(i)]=1
    else:
        D[fs(i)]+=1

ans=0

for i in D:
    if rnk[i]==D[i]:
        ans+=1
print(ans)