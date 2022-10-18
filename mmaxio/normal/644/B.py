from collections import deque

n, b = map(int, input().split())

q = deque()
for _ in range(n):
    t, d = map(int, input().split())
    while q and q[0] <= t:
        q.popleft()
    if len(q) == b + 1:
        print(-1, end = ' ')
    else:
        if q:
            t = q[-1]
        print(t + d, end = ' ')
        q.append(t + d)