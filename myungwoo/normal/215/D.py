N,M = map(int,raw_input().split())
ans = 0
for i in xrange(N):
    t,T,x,c = map(int,raw_input().split())
    if t >= T:
        ans += c+x*M
    else:
        ans += min(c+x*M,((M-1)/(T-t)+1)*c)
print ans