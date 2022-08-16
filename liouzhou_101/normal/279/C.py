n,m=map(int,raw_input().split())
a=[0]+map(int,raw_input().split())+[0]
L=[0]*(n+2)
R=[0]*(n+2)
R[1]=1
for i in range(2,n+1):
    R[i]=R[i-1] if a[i-1]>=a[i] else i
L[n]=n
for i in reversed(range(1,n)):
    L[i]=L[i+1] if a[i]<=a[i+1] else i
for i in range(m):
    x,y=map(int,raw_input().split())
    print "Yes" if L[x]>=R[y] else "No"