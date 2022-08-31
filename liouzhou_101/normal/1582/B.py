for test in range(int(input())):
	n = int(input())
	v = list(map(int, input().split()))
	a = 0
	b = 0
	for x in v:
		if x == 1:
			a += 1
		if x == 0:
			b += 1
	if a >= 1:
		print((2 ** b) * a)
	else:
		print(0)