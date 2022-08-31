h, m = map(int, input().split(':'))
for i in range(1440):
	b = m+i
	a = (h+b//60)%24
	b %= 60
	a = "%02d%02d" % (a, b)
	if a[::-1] == a:
		print(i)
		break