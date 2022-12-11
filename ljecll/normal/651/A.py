a, b = map(int, input().split())
ans = 0

while((a > 1 and b > 1) or (a == 1 and b > 1) or (b == 1 and a > 1)):
	ans = ans + 1
	if a > b:
		a, b = b, a
	a = a + 1
	b = b - 2
	#print(a, b)

print(ans)