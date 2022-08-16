import sys
input=sys.stdin.readline
t=int(input())
for _ in range(t):
    n=int(input())
    it=list(map(int,input().split()))
    su=0
    ma=-float("inf")
    for i in range(n-1):
        su+=it[i]
        ma=max(ma,su)
        su=max(su,0)
    su=0
    for i in range(1,n):
        su+=it[i]
        ma=max(ma,su)
        su=max(su,0)
    if sum(it)>ma:
        print("YES")
    else:
        print("NO")