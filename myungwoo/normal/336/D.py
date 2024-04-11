import math
MOD = 10**9+7

N,M,G = map(int,raw_input().split())

if M == 0:
    print int(G!=N%2)
    exit()
if M == 1:
    ans = int(G!=N%2)
    for i in xrange(N):
        if i%2 == G:
            ans += 1
    print ans
    exit()

D = [0 for i in xrange(N+1)]
D[0] = 1
for i in xrange(1,N+1):
    D[i] = D[i-1]*(i+M-1)%MOD*pow(i,MOD-2,MOD)%MOD
ans = 0
for i in xrange(N+1):
    if i%2 == G:
        a,b = N-i,M-1
        ans = (ans+D[a])%MOD
print ans