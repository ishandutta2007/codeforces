n, k = map(int, input().split())

arr = list(map(int, input().split()))

ans = 1000000007
cur = 0
pos = 0

for i in range(k):
	cur = cur + arr[i]

for i in range(k, n):
	if (cur < ans):
		ans = cur
		pos = i - k
	cur = cur - arr[i - k]
	cur = cur + arr[i]

if (cur < ans):
	ans = cur
	pos = n - k

pos = pos + 1

print(pos)