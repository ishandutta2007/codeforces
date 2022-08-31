def x(a):
    return int(a)+1
t=int(input())
for _ in range(t):
    a,b,c=map(int,input().split())
    
    
    if a<=b:
        if c<=b-a:
            print(0)
            continue
    low=0
    high=c
    while low<high:
        mid=(low+high)//2
        if a+mid>b+c-mid:
            high=mid
        else:
            low=mid+1

    print(c-low+1)
##        else:
##            ans=c-x((c+b-a)/2)+1
##            print(ans)
##    else:
##        if c==0:
##            print(1)
##            continue
##        ans=c-x((c+b-a)/2)+1
##        print(ans)