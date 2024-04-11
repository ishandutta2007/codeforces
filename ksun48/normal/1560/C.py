T = int(input())
for _ in range(T):
	v = int(input())
	s = 1
	while s ** 2 < v:
		s += 1
	if v > s ** 2 - s:
		print(s, (s ** 2 - v) + 1)
	else:
		print(v - (s-1) ** 2, s)