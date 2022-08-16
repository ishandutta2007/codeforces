t=int(input())
it=[]
for _ in range(t):
    n=int(input())
    mi=float("inf")
    ma=0
    for i in range(n):
        it.append(list(map(int,input().split())))
        ma=max(ma,it[-1][0])
        mi=min(mi,it[-1][1])
    print(max(ma-mi,0))