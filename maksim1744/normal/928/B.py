n, k = map(int, input().split())
a = list(map(int, input().split()))
d = [0] * n
a = [c - 1 for c in a]
for i in range(0, n):
    if a[i] == -1:
        d[i] = 1 + min(k, n - i - 1) + min(k, i)
    else:
        d[i] = 1 + min(k, n - i - 1) + min(k, i) + d[a[i]]
        lt = max(i - k, 0)
        rt = min(a[i] + k, n - 1)
        if lt <= rt:
            d[i] -= rt - lt + 1
print(*d)