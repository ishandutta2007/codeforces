from heapq import *
n,k=map(int,raw_input().split())
a=map(int,raw_input().split())
for _ in range(k):
    heappush(a,-heappop(a))
print sum(x for x in a)