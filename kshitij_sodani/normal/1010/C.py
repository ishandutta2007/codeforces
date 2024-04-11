from math import gcd
n,k=map(int,input().split())
it=list(map(int,input().split()))
it=[i%k for i in it]
it=[i for i in it if i!=0]

try:
    gc=it[0]
    for i in range(1,len(it)):
        gc=gcd(it[i],gc)
    gc=gcd(k,gc)
    print(k//gc)
    for i in range(k//gc):
        print(i*gc,end=" ")
except:
    print(1)
    print(0)