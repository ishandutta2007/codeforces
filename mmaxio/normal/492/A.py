def f(x):
	ret = 0
	delta = 0
	sz = 0
	while True:
		delta += 1
		sz += delta
		if x >= sz:
			x -= sz
			ret += 1
		else:
			return ret

print(f(int(input())))