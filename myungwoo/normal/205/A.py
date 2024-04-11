N=input()
A=map(int,raw_input().split())
k=min(A); p = 0; c = 0
for i in xrange(N):
    if A[i] == k:
        p = i+1; c += 1
print 'Still Rozdil' if c>1 else p