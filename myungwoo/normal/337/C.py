MOD = 10**9+9

def _pow(a,b):
    v = a; ret = 1
    for i in range(30):
        if (b>>i)&1 > 0:
            ret = ret*v%MOD
        v = v*v%MOD
    return ret

N,M,K = map(int,raw_input().split())
s = 0; e = N/K
while s <= e:
    m = (s+e)>>1
    probs = K*m; space = N-probs
    probs += space/K*(K-1)+space%K
    if probs >= M:
        e = m-1; t = m
    else:
        s = m+1
ans = (_pow(2,t+1)-2+MOD)*K%MOD
ans = (ans+M-K*t)%MOD
print ans