n,m,k=map(int,raw_input().split())
u=[-1 for i in range(n)]

def find(x):
  if u[x]<0:
    return x
  u[x]=find(u[x])
  return u[x]

def join(x,y):
  x=find(x)
  y=find(y)
  if x==y:
    return
  if u[y]<u[x]:
    x,y=y,x
  u[x]+=u[y]
  u[y]=x

c=map(int,raw_input().split())
for z in range(m):
  x,y=map(int,raw_input().split())
  join(x-1,y-1)
d=[{} for z in range(n)]
s=[0 for z in range(n)]
for i in range(n):
  k=find(i)
  s[k]+=1
  if c[i] not in d[k]:
    d[k][c[i]]=0
  d[k][c[i]]+=1
r=0
for i in range(n):
  m=0
  for z,a in d[i].items():
    m=max(m,a)
  r+=s[i]-m
print r