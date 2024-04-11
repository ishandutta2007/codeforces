def valid(x):
	s = str(x)
	seen = []
	for c in s:
		if c in seen:
			return False
		seen.append(c)
	return True

n = int(raw_input())
n += 1

while True:
	if valid(n):
		print n
		break
	n += 1