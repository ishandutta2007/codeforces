t=int(input())
for _ in range(t):
    a,b=map(int,input().split())
    a,b=sorted([a,b])
    diff=b-a
    low=0
    high=diff+1
    while low<high-1:
        mid=(low+high)//2
        if (mid*(mid+1))//2<diff:
            low=mid
        else:
            high=mid
    for i in range(low,high+1):
        if(i*(i+1))//2>=diff:
           ans=i
           break
    #print(ans)
    if ((ans*(ans+1))//2+a-b)%2==0:
        print(ans)
    else:
        ans+=1
        if ((ans*(ans+1))//2+a-b)%2==0:
            print(ans)
        else:
            ans+=1
            if ((ans*(ans+1))//2+a-b)%2==0:
                print(ans)