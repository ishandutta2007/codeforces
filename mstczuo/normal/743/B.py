[n, k] = map(int, raw_input().strip().split(' '))
k = k & -k

for i in range(100):
	if 2**i == k:
		print i + 1