read = lambda: map(int, input().split())

def test(a, b, c):
	if a > b:
		a, b = b, a
	if not (a <= c <= b):
		return -1
	return 1 if c == a or c == b else 0

def main():
	a = [tuple(read()) for _ in range(3)]
	if a[0][0] == a[1][0] == a[2][0] or a[0][1] == a[1][1] == a[2][1]:
		return 1
	for i in range(3):
		for j in range(i + 1, 3):
			if a[i][0] != a[j][0] and a[i][1] != a[j][1]:
				k = 3 ^ i ^ j
				x = test(a[i][0], a[j][0], a[k][0])
				y = test(a[i][1], a[j][1], a[k][1])
				if min(x, y) >= 0 and max(x, y) == 1:
					return 2
	return 3

print(main())