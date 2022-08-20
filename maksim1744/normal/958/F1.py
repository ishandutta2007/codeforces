n, m = map(int, input().split())
c = list(map(int, input().split()))
k = list(map(int, input().split()))
s = sum(k)
for i in range(n - s + 1):
    v = [0] * m
    for j in range(i, i + s):
        v[c[j] - 1] += 1
    if v == k:
        print('YES')
        exit(0)
print('NO')