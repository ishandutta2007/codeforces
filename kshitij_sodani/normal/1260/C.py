from math import gcd
t=int(input())

for _ in range(t):
    a,b,c=map(int,input().split())
    a,b=sorted([a,b])
    if a==b:
        print("OBEY")
        continue
    if b==1:
        print("OBEY")
        continue
##    if a==1:
##        if b<=c:
##            print("OBEY")
##        else:
##            print("REBEL")
##        continue
    x=gcd(a,b)
    di=(b-x-1)//a+1
    if di>=c:
        print("REBEL")
    else:
        print("OBEY")
    continue
##    if b%a!=0:
##        if di>=c:
##            print("REBEL")
##        else:
##            print("OBEY")
##        continue
##    else:
##        if di>c:
##            print("REBEL")
##        else:
##            print("OBEY")
##    continue