#list(map(int,input().split()))
t=int(input())
for i in range(t):
    n=int(input())
    it=list(map(int,input().split()))
    if n==1 and it[0]%2==1:
        print(-1)
    else:
        ind=-1
        ind2=-1
        ind3=-1
        for j in range(n):
            if it[j]%2==0:
                ind=j
            elif ind2==-1:
                ind2=j
            else:
                ind3=j
            
        if ind==-1:
            print(2)
            print(ind2+1,ind3+1)
        else:
            print(1)
            print(ind+1)