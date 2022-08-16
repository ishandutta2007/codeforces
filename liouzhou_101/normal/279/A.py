x,y=map(int,raw_input().split())
dx=[1,0,-1,0]
dy=[0,1,0,-1]
sx=sy=0
k=0
for i in range(1000):
    d=i/2+1
    tx,ty=sx+d*dx[k],sy+d*dy[k]
    k=(k+1)%4
    if min(sx,tx)<=x<=max(sx,tx) and min(sy,ty)<=y<=max(sy,ty):
        print i
        break
    sx,sy=tx,ty