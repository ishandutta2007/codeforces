t=int(input())
for _ in range(t):
    a=list(map(int,list(input())))
    b=[i for i in a if i%2==0]
    c=[i for i in a if i%2==1]
    ind=0
    ind2=0
    ans=[]
    while ind<len(b) and ind2<len(c):
        if b[ind]<c[ind2]:
            ans.append(b[ind])
            ind+=1
        else:
            ans.append(c[ind2])
            ind2+=1
    if ind<len(b):
        ans+=b[ind:]
    if ind2<len(c):
        ans+=c[ind2:]
    for i in ans:
        print(i,end="")
    print()