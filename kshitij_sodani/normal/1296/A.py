t=int(input())
for _ in range(t):
    n=int(input())
    it=list(map(int,input().split()))
    s=[i for i in it if i%2==1]
    if(len(s)>=1 and (len(s)<n or n%2==1)):
        print("YES")
    else:
        print("NO")