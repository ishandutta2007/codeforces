def solve():
	n, d = map(int, input().split())
	t = list(map(int, input().split()))

	sum_t = sum(t)
	if sum_t + 10 * (n - 1) > d:
		return -1
	
	ans = 2 * (n - 1) + (d - sum_t - 10 * (n - 1)) // 5
	return ans

print(solve())