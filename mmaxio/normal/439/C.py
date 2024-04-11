def solve():
	n, k, p = map(int, input().split())
	a = list(map(int, input().split()))

	even = list(filter(lambda x: x % 2 == 0, a))
	odd = list(filter(lambda x: x % 2 == 1, a))

	if (len(odd) - (k - p)) % 2 != 0:
		print('NO')
		return

	ans = [[] for _ in range(k)]

	for i in range(k - p):
		if odd:
			ans[i].append(odd.pop())
		else:
			print('NO')
			return

	for i in range(k - p, k):
		if even:
			ans[i].append(even.pop())
		elif len(odd) >= 2:
			ans[i].append(odd.pop())
			ans[i].append(odd.pop())
		else:
			print('NO')
			return

	ans[0] += even
	ans[0] += odd
	print('YES')
	for part in ans:
		print(len(part), ' '.join(map(str, part)))

solve()