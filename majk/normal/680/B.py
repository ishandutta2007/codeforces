N,T=map(int,input().split())
Q=list(map(int,input().split()))
B=min(T-1,N-T)
Ans=Q[T-1]
for i in range(B):
    if Q[T-1-i-1] == Q[T+i] == 1:
        Ans += 2
Ans += sum(Q[:T-B-1])
Ans += sum(Q[T+B:])
print(Ans)