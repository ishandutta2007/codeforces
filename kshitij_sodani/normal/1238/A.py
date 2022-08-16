t=int(input())
for _ in range(t):
    a,b=map(int,input().split())
    a,b=sorted([a,b])
    if abs(a-b)==1:
        print("NO")
    else:
        print("YES")