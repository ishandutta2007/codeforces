N,M = map(int,raw_input().split())
X = set(range(2,N))
Y = set(range(2,N))
for i in xrange(M):
    x,y = map(int,raw_input().split())
    if x in X:
        X.remove(x)
    if y in Y:
        Y.remove(y)
ans = len(X)+len(Y)
if N%2 == 1 and N/2+1 in X and N/2+1 in Y:
    ans -= 1
print ans