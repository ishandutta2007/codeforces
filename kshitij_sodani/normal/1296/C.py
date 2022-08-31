







import sys
input=sys.stdin.readline

t=int(input())
for _ in range(t):
    n=int(input())
    it=list(input())
    ss={}
    x=0
    y=0
    ss[(0,0)]=-1
    mi=n+1
    ans=[]
    for i in range(n):
        if it[i]=="L":
            x-=1
        elif it[i]=="R":
            x+=1
        elif it[i]=="U":
            y+=1
        else:
            y-=1
       # if x==0 and y==0:
        #    print(_)
       # print(x,y)
        try:
            xx=ss[(x,y)]
            if i+1-xx-2+1<mi:
                mi=i+1-xx-2+1
                ans=[xx+2,i+1]
        except:
            pass
        ss[(x,y)]=i
    if ans==[]:
        print(-1)
        continue
    print(*ans)