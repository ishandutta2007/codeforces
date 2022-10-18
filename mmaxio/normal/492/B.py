n, l = map(int, input().split())
a = sorted(map(int, input().split()))

ans = max(a[0], l - a[-1])
if len(a) > 1:
	ans = max(ans, max((a[i + 1] - a[i]) / 2 for i in range(n - 1)))

print(ans)