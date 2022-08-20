n = int(input())
a = list(map(int, input().split()))
b = sorted(a)
c = []
for i in range(n):
    for j in range(n - 1 - i):
        while a[j] - a[j + 1] >= 2:
            a[j] -= 1
            a[j + 1] += 1
        while a[j + 1] - a[j] >= 2:
            a[j + 1] -= 1
            a[j] += 1
    k = a.index(max(a))
    c.append(max(a))
    a = a[:k] + a[k + 1:]
if c[::-1] == b:
    print('YES')
else:
    print('NO')