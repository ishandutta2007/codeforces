get = lambda: [int(x) for x in raw_input().split()]

n, m, k = get()
block = get()
a = get()

can = [1] * n
for x in block:
    can[x] = 0
last_can = [0] * n
last = -1
for i in range(n):
    last_can[i] = i if can[i] else last
    last = last_can[i]

ans = 10**13
if can[0]:
    for i in range(k):
        step = i+1
        cnt = 1
        x = 0
        while x+step < n and last_can[x+step] > x:
            cnt += 1
            x = last_can[x+step]
        if x+step >= n:
            ans = min(ans, cnt * a[i])

print(-1 if ans == 10**13 else ans)