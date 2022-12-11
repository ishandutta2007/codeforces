n, x = map(int, input().split())
ans = 0

for i in range(n):
	c = input()
	v = int(c[2:])
	if (c[0] == '+'):
		x = x + v
	else:
		if (x < v):
			ans = ans + 1
		else:
			x = x - v

print(x, ans)