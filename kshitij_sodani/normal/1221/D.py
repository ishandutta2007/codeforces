import sys
input = iter(sys.stdin.buffer.read().decode().splitlines()).__next__
q=int(input())
for _ in range(q):
    n=int(input())
    dp=[[0,0,0] for i in range(n+1)]
    it=[-1]*n
    for __ in range(n):
        it[__]=list(map(int,input().split()))
    it.append([-100,-100])
    for i in range(n):
        for j in range(3):
            dp[i][j]=it[i][1]*j+min([dp[i-1][k] for k in range(3) if it[i-1][0]+k!=it[i][0]+j])
    print(min(dp[-2]))