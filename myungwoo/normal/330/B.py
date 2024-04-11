N,M = map(int,raw_input().split())
A = [i for i in xrange(1,N+1)]
for i in xrange(M):
    a,b = map(int,raw_input().split())
    if a in A:
        A.remove(a)
    if b in A:
        A.remove(b)
num = A[0]
print N-1
for i in xrange(1,N+1):
    if num != i:
        print num,i