import sys
input=sys.stdin.readline
t=int(input())
inf=10**18
for _ in range(t):
    n=int(input())
    it=list(map(int,input().split()))
    x=sum(it)
    y=it[0]
    for i in range(1,n):
        y=y^it[i]
   # print(x,y)
    if x%2==0:
        x+=inf
        y=(y^(inf))*2
        #print(y,x)
        print(3)
        print(inf,(y-x)//2,(y-x)//2)
    else:
        x+=inf-1
        y=(y^(inf-1))*2
        print(3)
        print(inf-1,(y-x)//2,(y-x)//2)