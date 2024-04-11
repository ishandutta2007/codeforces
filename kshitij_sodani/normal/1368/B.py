#list(map(int,input().split()))
n=int(input())
low=10
high=400
s="codeforces"
while(low<high-1):
    mid=(low+high)//2
    x=mid%10
    prod=1
    for i in range(10):
        if(i<x):
            prod*=(((mid)//10)+1)
        else:
            prod*=(mid//10)
    if(prod>=n):
        high=mid
    else:
        low=mid
mid=low
x=mid%10
prod=1
for i in range(10):
    if(i<x):
        prod*=(((mid)//10)+1)
    else:
        prod*=(mid//10)
mid=high
if(prod>=n):
    mid=min(mid,low)
x=mid%10
for i in range(10):
    if(i<x):
        print(s[i]*((mid//10)+1),end="")
            #prod*=(((mid)//10)+1)
    else:
        print(s[i]*((mid//10)),end="")
print()
    
##mi=float("inf")
##ans=""
##for k in range(1,11):
##    i=1
##    while (i**k)<n:
##        i+=1
##    if(i*k+(10-k)<mi):
##        mi=(i*k+(10-k))
##        if(mi>400):
##            continue
##      #  ans=""
##        kk=0
##      #  print(k)
##       
##        for j in "codeforces":
##            if(kk<k):
##                
##               ans+=j*i
##            else:
##                ans+=j
##         #   print(j*i,end="")
##            kk+=1
##print(ans)