n = int(input())
m = [0 for i in range(n)]
for i in range(n - 1):
    u, v = map(int, input().split())
    m[u - 1] += 1
    m[v - 1] += 1
print(m.count(1))