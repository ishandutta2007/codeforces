arr = []
vis = [0] * 100001
ans = [0] * 100000
query = []
num = 0

N, Q = map(int, input().split())

arr = list(map(int, input().split()))

for i in range(N - 1, -1, -1):
	if (vis[arr[i]] == 0):
		vis[arr[i]] = 1
		num = num + 1
	ans[i] = num

for i in range(Q):
	x = int(input())
	#print(x)
	x = x - 1
	print(ans[x])