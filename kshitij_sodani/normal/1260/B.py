t=int(input())
for _ in range(t):
    a,b=map(int,input().split())
    a,b=sorted([a,b])
    if a==1 and b==1:
        print("NO")
        continue
    d=b-a
    if d>a:
        print("NO")
        continue
    y=(2*b-a)/3
    if y%1!=0:
        print("NO")

        continue
    x=(a-y)/2

    if x%1==0 and y>=0:
        print("YES")
    else:
        print("NO")