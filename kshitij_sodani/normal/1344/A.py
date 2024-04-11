t=int(input())
for _ in range(t):
    n=int(input())
    it=list(map(int,input().split()))
    aa=set()
    j=1
    for i in it:
        aa.add((j-1+i)%n)
        j+=1
    if(len(aa)==n):
        print("YES")
    else:
        print("NO")