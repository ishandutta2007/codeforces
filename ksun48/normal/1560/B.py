T = int(input())
for _ in range(T):
	a,b,c = [int(x) for x in input().split()]
	n = abs(a-b) * 2
	if a > n or b > n or c > n:
		print(-1)
	else:
		print((c-1 + n // 2) % n + 1)