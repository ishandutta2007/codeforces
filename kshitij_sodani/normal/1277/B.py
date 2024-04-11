from heapq import *
t=int(input())
for _ in range(t):
    n=int(input())
    it=list(map(int,input().split()))
    it=[-i for i in it if i%2==0]
    heapify(it)
    tot=0
    tot=0
    ss=set()
    while it:
        no=it.pop()
        if no in ss:
            continue
        ss.add(no)
        if no%4==0:
            heappush(it,no//2)
        tot+=1
    print(tot)