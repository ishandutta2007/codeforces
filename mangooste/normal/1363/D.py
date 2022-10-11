from sys import stdout
t = int(input())
for _ in range(t):
	n, k = map(int, input().split())
	S = [[] for _ in range(k)]
	for i in range(k):
		S[i] = list(map(int, input().split()))
		S[i] = S[i][1:]
	print("?", n, end = " ");
	for i in range(n):
		print(i + 1, end = " ")
	print()
	stdout.flush()
	max_el = int(input())
	L = 0
	R = n + 1
	while R - L > 1:
		mid = (L + R) // 2
		print("?", mid, *list(range(1, mid + 1)))
		stdout.flush()
		cur_max = int(input())
		if (cur_max == max_el):
			R = mid
		else:
			L = mid
	ans = [0] * k
	for i in range(k):
		if S[i].count(R) == 0:
			ans[i] = max_el
		else:
			cur = []
			for j in range(n):
				if (S[i].count(j + 1) == 0):
					cur.append(j + 1)
			print("?", len(cur), *cur)
			stdout.flush()
			ans[i] = int(input())
	print("!", *ans)
	stdout.flush()
	s = input()
	if (s == "Incorrect"):
		exit()