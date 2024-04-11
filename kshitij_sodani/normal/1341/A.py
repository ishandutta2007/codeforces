#list(map(int,input().split()))
t=int(input())
for _ in range(t):
    n,a,b,c,d=map(int,input().split())
    if((a-b)*n>c+d or (a+b)*n<c-d):
        print("No")
    else:
        print("Yes")