import sys
readline = sys.stdin.readline

N = int(readline())

DP = [0] * (N+1)
MAX = 2100
last_t = [0] * MAX

for i in range(1, N + 1):
    DP[i] = DP[i-1]
    a, b = readline().split()
    b = int(b)
    if(a == "win"):
        DP[i] = DP[i-1]
        last_t[b] = i
    else:
        if last_t[b] == 0:
            continue
        DP[i] = max(DP[i], DP[last_t[b]] + (1 << b))

print(DP[-1])