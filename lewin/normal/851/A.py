n,k,t = map(int, raw_input().split())

if t <= k:
    print t
elif t >= n:
    print n + k - t
else:
    print k