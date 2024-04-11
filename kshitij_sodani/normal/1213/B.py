t=int(input())
for _ in range(t):
    n=int(input())
    it=list(map(int,input().split()))
    mi=max(it)+1
    tot=0
    for i in it[-1::-1]:
        if i>mi:
            tot+=1
        mi=min(i,mi)
    print(tot)