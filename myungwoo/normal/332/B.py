N,K = map(int,raw_input().split())
A = map(int,raw_input().split())
S = [0 for i in range(N-K+1)]
s = sum(A[:K-1])
for i in range(K-1,N):
    s += A[i]
    S[i-K+1] = s
    s -= A[i-K+1]
X,Y = 0,K
x = 0
for i in range(K,N-K+1):
    if S[x] < S[i-K]:
        x = i-K
    if S[X]+S[Y] < S[x]+S[i]:
        X,Y = x,i
print X+1,Y+1