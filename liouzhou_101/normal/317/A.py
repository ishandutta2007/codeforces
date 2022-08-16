x,y,m=map(int,raw_input().split())
if x>=m or y>=m:
    print 0
    exit()
if x<=0 and y<=0:
    print -1
    exit()
if x>y:
    x,y=y,x
ans=0
if x<0:
    x=-x
    k=(x-1)/y+1
    x=k*y-x
    ans+=k
if x>y:
    x,y=y,x
while y<m:
    x,y=y,x+y
    ans+=1
print ans