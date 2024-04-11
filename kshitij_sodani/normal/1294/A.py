t=int(input())
for _ in range(t):
    a,b,c,n=map(int,input().split())
    a,b,c=sorted([a,b,c])
    x=2*c-b-a
   # print(x)
    if n<x:
        print("NO")
    elif (x-n)%3==0:
        print("YES")
    else:
        print("NO")