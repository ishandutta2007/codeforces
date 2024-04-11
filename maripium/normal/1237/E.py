N = 1000001
ans = [0 for x in range(N)]
cur = 1
while (cur < N) :
    ans[cur] = 1
    cur += 1
    ans[cur] = 1
    cur += 2 * (cur // 2)
n = int(input())
print(ans[n])