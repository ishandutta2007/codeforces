a, b, c, d, e, f = map(int, input().split())
if c == 0 and d != 0:
	print("Ron")
	exit(0)
if a == 0 and b != 0 and d != 0:
	print("Ron")
	exit(0)
if b * d * f > a * c * e:
	print("Ron")
else:
    print("Hermione")