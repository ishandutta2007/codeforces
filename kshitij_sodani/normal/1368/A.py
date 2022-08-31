#list(map(int,input().split()))
t=int(input())
for _ in range(t):
    a,b,n=list(map(int,input().split()))
    tot=0
    while(max(a,b)<=n):
        tot+=1
        if(a<b):
            a+=b
        else:
            b+=a
    print(tot)