#list(map(int,input().split()))
t=int(input())
for _ in range(t):
    n,r=map(int,input().split())
    r=min(r,n)
    if(r==n):
        su=((r-1)*(r))//2
        su+=1
        print(su)
    else:
        print((r*(r+1))//2)