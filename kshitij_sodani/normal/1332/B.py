t=int(input())

xx=[2,3,5,7,11,13,17,19,23,29,31]
for _ in range(t):
    n=int(input())
    aa=list(map(int,input().split()))
    x=[0 for i in range(n)]
    y=set()
    jj=0
    for i in aa:
        k=1
        for j in xx:
            if i%j==0:
                ind=k
                y.add(k)
                break
            k+=1
        x[jj]=k
        jj+=1
    ss={}
    l=0
    for i in y:
        l+=1
        ss[i]=l
    print(len(y))
    for i in x:
        print(ss[i],end=" ")
    print()