N,M=map(lambda x:int(x),raw_input().split())
X = set(range(2,N))
Y = set(range(2,N))
for i in xrange(M):
    x,y = map(lambda x:int(x),raw_input().split())
    if x in X: X.remove(x)
    if y in Y: Y.remove(y)
print len(X)+len(Y)-(1 if N%2 == 1 and N/2+1 in X and N/2+1 in Y else 0)