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
n= int(input())
a = [int (e) for e in input().split()]
c1=0
c2=0
for i in range(n):
    if(a[i]%2==0):
        c1+=1
    else:
        c2+=1
print(min(c1,c2))