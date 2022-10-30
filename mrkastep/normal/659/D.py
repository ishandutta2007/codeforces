n=int(input())
a=[]

tr=0
tl=0

for i in range(0,n+1):
    p=input().split()
    p[0]=int(p[0])
    p[1]=int(p[1])
    a.append(p)
a.append(a[0])

for i in range(0,n):
    x1=a[i+1][0]-a[i][0]
    y1=a[i+1][1]-a[i][1]
    x2=a[i+2][0]-a[i+1][0]
    y2=a[i+2][1]-a[i+1][1]
    if x1>0:
        if y2>0:
            tl+=1
        else:
            tr+=1
    elif x1<0:
        if y2<0:
            tl+=1
        else:
            tr+=1
    elif y1>0:
        if x2<0:
            tl+=1
        else:
            tr+=1
    else:
        if x2>0:
            tl+=1
        else:
            tr+=1

print(str(min(tl,tr)))