n=int(input())
it=list(map(int,input().split()))
a=[i for i in it if i<=-1]
b=[i for i in it if i>=1]
c=n-len(a)-len(b)

if len(a)%2==0:
    print(sum([-1-i for i in a])+sum([i-1 for i in b])+1*c)
if len(a)%2==1:
    if c!=0:
        print(sum([-1-i for i in a])+sum([i-1 for i in b])+1*c)
    else:
        aa=sum([-1-i for i in a])
        bb=-1-max(a)
        cc=sum([i-1 for i in b])
        d=1-max(a)
        
        print(aa-bb+cc+d)