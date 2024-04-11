n, s = map(int, input().split())

if n == 1 and s == 10:
	print(-1)
else:
	ans = 10**(n - 1)
	while ans % s != 0:
		ans += 1
	print(ans)