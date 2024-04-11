#list(map(int,input().split()))
t=int(input())
for _ in range(t):
    n=int(input())
    aa=list(map(int,input().split()))
    bb=[i+1 for i in range(2*n) if aa[i]%2==0]
    cc=[i+1 for i in range(2*n) if aa[i]%2==1]
    co=n-1
    for i in range(0,len(bb)-1,2):
        if(co==0):
            break
        co-=1
        print(bb[i],bb[i+1])
    for i in range(0,len(cc)-1,2):
        if(co==0):
            break
        co-=1
        print(cc[i],cc[i+1])