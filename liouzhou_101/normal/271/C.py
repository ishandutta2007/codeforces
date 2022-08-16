n,k=map(int,raw_input().split())
if k*3>n or k==1:
    print -1
else:
    for i in range(1,n+1):
        if i<=k*2:
            print (i-1)//2+1,
        elif i<=k*3:
            print i-k*2,
        else:
            print 1