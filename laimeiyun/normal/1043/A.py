n = input()
a = map(int, raw_input().split())

s = sum(a)
m = max(a)

for k in range(m, 1000):
	if k * n - s > s:
		print k
		break