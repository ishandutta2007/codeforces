N,M = map(int,raw_input().split())
A = sorted(map(int,raw_input().split())) if M else [0]
for i in range(2,M):
    if A[i-2] == A[i]-2 and A[i-1] == A[i]-1:
        print 'NO'
        exit()
print 'NO' if A[0] == 1 or A[-1] == N else 'YES'