import sys
input=sys.stdin.readline
n,a,b=map(int,input().split())
up=0
left=0
right=0
down=0
for i in range(n):
    c,d=map(int,input().split())
    if c<a:
        up+=1
    if c>a:
        down+=1
    if d<b:
        left+=1
    if d>b:
        right+=1
ma=0
ind=[0,0]
if a==0 and b==0:
    ind=[1,1]
for i in [[1,0,down],[-1,0,up],[0,-1,left],[0,1,right]]:
    aa=a+i[0]
    bb=b+i[1]
    if aa<0 or bb<0 or aa>10**9 or bb>10**9:
        continue
    if i[2]>ma:
        ma=i[2]
        ind=[aa,bb]
print(ma)
print(*ind)