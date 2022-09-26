import sys
n, m = map(int, input().split())
a = [[] for x in range (n)]
for i in range (n):
	a[i] = list(map(int, input().split()))
b = [[0 for j in range(m)] for i in range(n)]
ans = []
for i in range(n - 1):
	for j in range(m - 1):
		if (a[i][j] == 1 and a[i][j + 1] == 1 and a[i + 1][j] == 1 and a[i + 1][j + 1] == 1):
			ans.append((i, j))
			b[i][j] = 1
			b[i][j + 1] = 1
			b[i + 1][j] = 1
			b[i + 1][j + 1] = 1
for i in range(n):
	for j in range(m):
		if (a[i][j] != b[i][j]):
			print(-1)
			sys.exit()
print(len(ans))
for p in ans:
    x, y = p
    print(x + 1, y + 1)