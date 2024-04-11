
def extEuc(a, b):
	if b == 0:
		return (a, 1, 0)
	k = a // b
	sub = extEuc(b, a - k*b)
	return (sub[0], sub[2], sub[1] - k*sub[2])

[n, p, w, d] = [int(t) for t in input().split()]
# aw + bd = p, a+b <= n

params = extEuc(w, d);
gd = params[0]
a = params[1]
b = params[2];

if p % gd != 0:
	print("-1")
else:
	k = p // gd
	a *= k
	b *= k

	# can add a += d / gcd, b -= w / gcd
	# make both positive
	x = d // gd;
	y = w // gd;
	if a < 0:
		cou = (abs(a) + x-1) // x
		a += cou*x
		b -= cou*y
	elif b < 0:
		cou = (abs(b) + y-1) // y;
		a -= cou*x;
		b += cou*y;
	if a < 0 or b < 0:
		print("-1")
	else:
		# Minimize sum a+b
		if x > y:
			cou = a // x;
			a -= cou*x;
			b += cou*y;
		else:
			cou = b // y;
			a += cou*x;
			b -= cou*y;
		
		# Check
		if a + b <= n:
			print(str(a) + ' ' + str(b) + ' ' + str(n - (a + b)))
		else:
			print("-1")