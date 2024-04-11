#list(map(int,input().split()))
t=int(input())
for _ in range(t):
    a,b,c,d=list(map(int,input().split()))
    x,y,x1,y1,x2,y2=list(map(int,input().split()))
    if(x1==x and x1==x2):
        if(a>0 or b>0):
            print("NO")
            continue
    if(y1==y and y1==y2):
        if(d>0 or c>0):
            print("NO")
            continue
    xx=min(c,d)
    c-=xx
    d-=xx
    yy=min(a,b)
    a-=yy
    b-=yy
    if(x-a>=x1 and x+b<=x2 and y+d<=y2 and y-c>=y1):
        print("YES")
    else:
        print("NO")