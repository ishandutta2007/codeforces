
from heapq import *
t=int(input())
for _ in range(t):
    n,a,b=map(int,input().split())
    aa=[-i for i in list(map(int,input().split()))]
    heapify(aa)
    bb=[-i for i in list(map(int,input().split()))]
    heapify(bb)
    while aa and bb:
        if -aa[0]>-bb[0]:
            x=heappop(bb)
            heappush(aa,x)
        else:
            x=heappop(aa)
            heappush(bb,x)
    if bb==[]:
        print("YES")
    else:
        print("NO")