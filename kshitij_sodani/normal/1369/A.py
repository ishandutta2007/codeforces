#list(map(int,input().split()))
t=int(input())
for _ in range(t):
    n=int(input())
    if(n%4>0):
        print("NO")
    else:
        print("YES")