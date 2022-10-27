"""
useful stuff 
x= list(map(int,input().split()))
x =[int (e) for e in input().split()]

swap x,y=y,x
substring a[x:y] mean x to y-1

print list
print(*list)
print(' '.join(map(str,listname)))

start from 1 to n
for i in range(1,n+1)

Don't froget dumb stuff like:
if: 
for:
while: 
and tab
def doesn't require data type
"""
z= []
a = []
for i in range (200010):
    a.append([])
n,k = [int (e) for e in input().split()]
b = [int (e) for e in input().split()]
for x in b:
    c=x
    ct=0
    a[x].append(0)
    while(c!=0):
        c>>=1
        ct+=1
        a[c].append(ct)
ans=10000000000
for i in range(200000):
    if(len(a[i])<k):
        continue
    a[i].sort()
    s=0
    for j in range(k):
        s+=a[i][j]
    ans=min(ans,s)
print(ans)