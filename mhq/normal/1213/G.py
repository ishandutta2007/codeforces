n, m = map(int, input().split())
maxN = 2 * (10 ** 5) + 10
edges = [[] for i in range(0, maxN)]
que = [[] for _ in range(0, maxN)]
ans = [0] * m
sz = [1 for _ in range(0, n)]
p = [i for i in range(0, n)]
total_sum = 0

def get(u):
    if p[u] == u:
        return u
    p[u] = get(p[u])
    return p[u]


def unite(u, v):
    u = get(u)
    v = get(v)
    if u == v:
        return
    global total_sum
    total_sum -= (sz[u] * (sz[u] - 1)) // 2
    total_sum -= (sz[v] * (sz[v] - 1)) // 2
    total_sum += ((sz[u] + sz[v]) * (sz[u] + sz[v] - 1)) // 2
    if sz[u] < sz[v]:
        p[u] = v
        sz[v] += sz[u]
    else:
        p[v] = u
        sz[u] += sz[v]


for i in range(1, n):
    u, v, w = map(int, input().split())
    u -= 1
    v -= 1
    edges[w].append((u, v))
ques = list(map(int, input().split()))

for i in range(0, m):
    que[ques[i]].append(i)
for i in range(0, maxN):
    for u, v in edges[i]:
        unite(u, v)
    for id in que[i]:
        ans[id] = total_sum
print(" ".join(str(x) for x in ans))