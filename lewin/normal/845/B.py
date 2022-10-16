x = raw_input()

def solve(ss, su):
	a = sum(map(int, ss))
	if a == su:
		return 0

	b = 3
	for keep in range(1<<3):
		aa = 0
		cc = 3
		for i in range(3):
			if ((keep>>i)&1):
				aa += ord(ss[i]) - ord('0')
				cc -= 1

		if 0 <= (su - aa) <= cc * 9:
			b = min(b, cc)
	return b

ans = 6
for s in range(0, 28):
	s1 = x[:3]
	s2 = x[3:]

	b1 = solve(s1, s)
	b2 = solve(s2, s)

	ans = min(ans, b1+b2)

print ans