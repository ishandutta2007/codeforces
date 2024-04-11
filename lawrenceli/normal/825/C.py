n, k = map(int, raw_input().split())
a = list(map(int, raw_input().split()))
a.sort()
ans = 0
p = 0
while p < len(a):
    while p < len(a) and a[p] <= 2 * k:
        k = max(k, a[p])
        p += 1
    if p >= len(a): break;

    k *= 2
    ans += 1
print ans