#list(map(int,input().split()))
t=int(input())
for _ in range(t):
    n,m=list(map(int,input().split()))
    print((n*m+1)//2)
    continue
    if(n%2==0):
        print((n//2)*m)
    elif(n%2==1 and m%2==1):
        print((n//2)*m+(n+1)//2)
    else:
        print((m//2)*n)