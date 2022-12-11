t = int(input())

for i in range(t):
	a, b, k = map(int, input().split())
	if (k & 1):
		print(((k + 1) >> 1) * a - ((k - 1) >> 1) * b)
	else:
		print((k >> 1) * a - (k >> 1) * b)