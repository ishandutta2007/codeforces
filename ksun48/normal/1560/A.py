T = int(input())
for i in range(T):
	k = int(input())
	cnt = 0
	for v in range(1, 10 ** 4):
		if v % 3 == 0 or v % 10 == 3:
			continue
		cnt += 1
		if cnt == k:
			print(v)
			break