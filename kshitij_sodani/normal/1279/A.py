t=int(input())
for _ in range(t):
    a,b,c=map(int,input().split())
    a,b,c=sorted([a,b,c])
    if a+b>=c-1:
        print("Yes")
    else:
        print("No")