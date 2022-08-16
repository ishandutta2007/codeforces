#list(map(int,input().split())))
t=int(input())
for _ in range(t):
    n,x=map(int,input().split())
    aa=list(map(int,input().split()))
    ss=set()
    tot=x
    for i in aa:
        ss.add(i)
    ans=0
    for i in range(1,300):
        if i not in ss:
            tot-=1
            if(tot<0):
                ans=i-1
                break
    print(ans)