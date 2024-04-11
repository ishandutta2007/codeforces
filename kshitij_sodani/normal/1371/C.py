#list(map(int,input().split()))
t=int(input())
for _ in range(t):
    a,b,n,m=map(int,input().split())
    if(a+b<n+m):
        print("NO")
        continue
    if(a>b):
        a,b=b,a
    x=min(n,b-a)
    b-=x
    n-=x
    if(a==b):
        xx=min(n,m)
        n-=xx
        m-=xx
        a-=xx
        b-=xx
        if(a<0 or b<0):
            print("NO")
            continue
        if(min(a,b)<m):
            print("NO")
            continue
        if(a+b<n):
            print("NO")
            continue
    else:
     #   print(a,b)
        if(min(a,b)<m):
            print("NO")
            continue
    print("YES")
    continue