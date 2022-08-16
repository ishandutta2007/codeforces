from math import gcd
def s(p):
    global oo
    s={}
    tot=0
    j=0
    for i in range(p//oo):
        tot+=it[i]*(a+b)//100
        
        j+=1
    for i in range(p//y):
        l=(i+1)*y
        
        if l%oo==0:
            continue
        tot+=it[j]*b/100
        j+=1
      #  print(tot)
    for i in range(p//x):
        l=(i+1)*x
        if l%oo==0:
            continue
        tot+=it[j]*a/100
        j+=1
       # print(tot)
   # print(p,tot)
    return tot>=k
        
t=int(input())
for _ in range(t):
    n=int(input())
    it=list(map(int,input().split()))
    it.sort(reverse=True)
    a,x=map(int,input().split())
    b,y=map(int,input().split())
    if a>b:
        x,y,a,b=y,x,b,a
    k=int(input())
    oo=(x*y)//gcd(x,y)

    ans=s(n)
    if ans==False:
        print(-1)
        continue
    low=1
    high=n
    while low<high:
        mid=(low+high)//2
        ans=s(mid)
        if ans==False:
            low=mid+1
        else:
            high=mid
    print(low)