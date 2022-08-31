import sys
m,n=map(int,input().split())
p=[]
for i in range(n):
    print(1) 
    sys.stdout.flush()
    a=int(input())
    if a==-1:
        p.append(-1)
    if a==1:
        p.append(1)
    if a==0:
        break
if a!=0:
    low=2
    high=m
    k=0
    while True:
        k%=n
        mid=(low+high)//2
        print(mid)
        sys.stdout.flush()
        a=int(input())
        #print(a,p[k])
        if a==0:
            break
        if p[k]==-1:
            if a==-1:
                a=1
            else:
                a=-1
        if a==1:
            low=mid+1
        elif a==-1:
            high=mid-1
        if a==0:

            break
        k+=1