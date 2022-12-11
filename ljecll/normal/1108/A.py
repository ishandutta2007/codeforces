q = int(input())

for i in range(q):
	a, b, c, d = map(int, input().split())
	if (a == d):
		print(b, c)
	else:
		print(a, d)