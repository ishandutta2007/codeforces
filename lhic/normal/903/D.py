n = int(input())
a = list(map(int, input().split()))
ans = 0
mm = dict((a[i], 0) for i in range(n))
for i in range(n):
    ans += a[i] * (i - (n - 1 - i))
    mm[a[i]] += 1
    ans -= mm.get(a[i] - 1, 0)
    ans += mm.get(a[i] + 1, 0)
print(ans)