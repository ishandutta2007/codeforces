t=int(input())
for _ in range(t):
    n,k=map(int,input().split())
    if k==1:
        print(n)
        continue
    nn=n
    tot=0
    while nn>=k:
        tot+=nn%k
        tot+=1
       # print(tot,nn)
        nn=nn//k
    tot+=nn
    print(tot)