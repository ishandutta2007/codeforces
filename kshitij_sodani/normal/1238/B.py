import sys
input=sys.stdin.readline
import bisect as bs
q=int(input())
for _ in range(q):
    n,rr=map(int,input().split())
    it=list(set(list(map(int,input().split()))))
    it.sort()
    l=0
    r=len(it)-1
    d=0
    tot=0
    while r>=l and r>=0 and l>=0:
        d+=rr
        l=bs.bisect_right(it,d)
        r-=1
        tot+=1
    #    print(l,r)
    print(tot)