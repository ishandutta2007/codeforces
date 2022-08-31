n, m = map(int, input().split())
clr = [-1 for i in range(0, n)]
eds = []


def dfs():
    cur = 0
    st = [-1 for i in range(0, n + 1)]
    st[cur] = 0
    cur += 1
    while cur > 0:
        v = st[cur - 1]
        cur -= 1
        for x in g[v]:
            if clr[x] != -1:
                if clr[x] == clr[v]:
                    return False
                continue
            clr[x] = clr[v] ^ 1
            st[cur] = x
            cur += 1
    return True


g = [[] for i in range(0, n)]
for i in range(0, m):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    g[u].append(v)
    g[v].append(u)
    eds.append((u, v))
clr[0] = 0
if dfs():
    print("YES")
    print("".join("1" if clr[u] < clr[v] else "0" for (u, v) in eds))
else:
    print("NO")