n, m = map(int, input().split())
arr = list(map(int, input().split()))
ans = 0

arr.sort()

for i in range(m):
	if (arr[i] < 0):
		ans += arr[i]
		
print(-ans)