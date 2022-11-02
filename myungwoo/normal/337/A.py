N,M = map(lambda x:int(x),raw_input().split())
A = sorted(map(lambda x:int(x),raw_input().split()))
ans = 9999
for i in range(M-N+1):
    ans = min(ans,A[i+N-1]-A[i])
print ans