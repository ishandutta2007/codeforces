q=int(input())
for _ in range(q):
    n,m=map(int,input().split())
    x=n//m
    y=x%10
    if (m%10)==0:
        print(0)
        continue
    d=m%10
    if d==5:
        tot=(x//2)*5
        if x%2==1:
            tot+=5
        print(tot)
        continue
    if d%2==0:
        tot=(x//10)*40
        for i in range(y):
            tot+=(m*(i+1))%10
    elif d%2==1:
        tot=(x//10)*45
        for i in range(y):
            tot+=(m*(i+1))%10
    print(tot)