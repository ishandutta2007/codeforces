n, k = map(int, input().split())

arr = list(map(int, input().split()))

ans = 0

for i in range(1, n):
	cur = max(0, k - arr[i] - arr[i - 1])
	arr[i] = arr[i] + cur
	ans = ans + cur

print(ans)
print(*arr)