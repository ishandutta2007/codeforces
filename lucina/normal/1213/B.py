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
t= int(input())
for tt in range(t):
    mi=10000000000
    n=int(input())
    a=[int (e) for e in input().split()]
    i=n-1
    ct=0
    while(i>=0):
        if(i!=n-1 and a[i]>mi):
            ct+=1
        mi=min(mi,a[i])
        i-=1
    print(ct)