T = int(input())
for _ in range(T):
	s = input()
	ans = 64
	for i in range(60):
		t = str(1 << i)
		saved = 0
		k = 0
		while saved < len(t) and k < len(s):
			if t[saved] == s[k]:
				saved += 1
			k += 1
		ans = min(ans, len(s) + len(t) - 2 * saved)
	print(ans)