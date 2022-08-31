import sys
input=sys.stdin.readline
x,y,a,aa,b,bb=map(int,input().split())
xx,yy,t=map(int,input().split())
no=[[x,y]]
for i in range(200):
    no.append([no[-1][0]*a+b,no[-1][1]*aa+bb])
ma=0
for i in range(200):
    tot=0
    co=0
    tot+=abs(no[i][0]-xx)+abs(no[i][1]-yy)
    if tot>t:
        continue
    co=1
    for j in range(i+1,200):
        tot+=abs(no[j][0]-no[j-1][0])+abs(no[j][1]-no[j-1][1])
        if tot>t:
            break
        co+=1
   # if co>ma:
   #     print(i)
    ma=max(ma,co)
for i in range(199,-1,-1):
    tot=0
    co=0
    tot+=abs(no[i][0]-xx)+abs(no[i][1]-yy)
    if tot>t:
        continue
    co=1
    for j in range(i-1,-1,-1):
        tot+=abs(no[j][0]-no[j+1][0])+abs(no[j][1]-no[j+1][1])
        if tot>t:
            break
        co+=1
    ##   print(i)
    ma=max(ma,co)
    

print(ma)