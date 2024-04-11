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
q=int(input())
p =[0,10,5,10,5,2,5,10,5,10]
for qq in range(q):
    n,m= [int (e) for e in input().split()]
    x=m%10
    if(x==0):
        print(0)
        continue
    s=0
    cur=x
    for i in range (p[x]):
        s+=cur
        cur+=x
        cur%=10
    res = n//m
    ans=0
    ans+= s*(res//p[x])
    rr= res %p[x]
    cur=x
    for i in range(rr):
        ans+=cur
        cur+=x
        cur%=10
    print(ans)