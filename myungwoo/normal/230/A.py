import sys
S, N = map(int,raw_input().split())
A = []
for i in range(N):
    A.append(map(int,raw_input().split()))
A.sort()
for x,y in A:
    if S > x: S += y
    else:
        print 'NO'
        sys.exit(0)
print 'YES'