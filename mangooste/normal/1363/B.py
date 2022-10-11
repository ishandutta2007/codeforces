t = int(input())
for _ in range(t):
	s = input()
	n = len(s)
	zero = 0; one = 0
	for i in range(n):
		if s[i] == '1':
			one += 1
		else:
			zero += 1
	cur_zero = 0; cur_one = 0
	ans = min(zero, one)
	for i in range(n):
		if s[i] == '1':
			cur_one += 1
		else:
			cur_zero += 1
		ans = min(ans, cur_one + zero - cur_zero, cur_zero + one - cur_one)
	print(ans)