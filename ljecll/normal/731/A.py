s = str(input())

c = 'a'

ans = 0

for ch in s:
	x = ord(ch) - ord(c)
	if x < 0:
		x = x + 26
	if x > 13:
		x = 26 - x
	ans = ans + x
	c = ch

print(ans)