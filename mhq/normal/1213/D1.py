import math
from heapq import merge
n, k = map(int, input().split())
maxN = 2 * (10 ** 5) + 10
cnt = [list() for i in range(0, maxN + 1)]
a = list(map(int, input().split()))
for c in a:
    cnt[c].append(0)
best = 1000000000
for i in range(maxN - 1, -1, -1):
    if 2 * i < maxN:
        cnt[2 * i] = [x + 1 for x in cnt[2 * i]]
        for p in cnt[2 * i]:
            p += 1
    if 2 * i + 1 < maxN:
        cnt[2 * i + 1] = [x + 1 for x in cnt[2 * i + 1]]
    if 2 * i < maxN:
        cnt[i] = list(merge(cnt[i], list(merge(cnt[2 * i], cnt[2 * i + 1]))))
    while len(cnt[i]) > k:
        cnt[i].pop()
    if len(cnt[i]) == k:
        best = min(best, sum(cnt[i]))
print(best)