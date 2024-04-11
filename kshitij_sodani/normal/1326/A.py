#list(map(int,input().split()))
t=int(input())
for _ in range(t):
    n=int(input())
    if(n==1):
        print(-1)
    else:
        print("5"+"9"*(n-1))