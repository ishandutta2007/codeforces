a, b, c = map(int, raw_input().split(' '))
l = [a, b, c]
l.sort()
[a, b, c] = l
if a % 2 == b % 2 == c % 2:
	print b
else:
	if a % 2 == b % 2:
		print b
	elif a % 2 == c % 2:
		print c
	else:
		print c