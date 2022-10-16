import math
r,d = map(int, raw_input().split())

n = int(raw_input())
ans = 0
mindist = r-d
maxdist = r
for i in range(n):
    x,y,ri = map(int, raw_input().split())
    dist = math.sqrt(x*x+y*y)
    if dist-ri >= mindist and dist+ri <= maxdist:
        ans += 1
print ans