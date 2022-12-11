a, b, c, d = map(int, (input()).split())

if c < d:
	c, d = d, c
if b < c:
	b, c = c, b
if a < b:
	a, b = b, a

print(a - b, a - c, a - d)