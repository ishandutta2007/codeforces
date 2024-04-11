t = int(raw_input())

def get(n,m,is_white):
	# return white black
	if n < 0 or m < 0:
		return 0, 0

	nblack = (n*m)/2
	nwhite = n*m - nblack

	if is_white:
		return nwhite, nblack
	else:
		return nblack, nwhite

def intersect(a,b,c,d):
	if a > c:
		return intersect(c,d,a,b)
	return b >= c

for __ in xrange(t):
	n,m = map(int, raw_input().split())

	x1,y1,x2,y2 = map(int, raw_input().split())

	x3,y3,x4,y4 = map(int, raw_input().split())

	nwhite, nblack = get(n, m, True)

	w1, b1 = get(x2 - x1 + 1, y2 - y1 + 1, (x1 + y1) % 2 == 0)
	w2, b2 = get(x4 - x3 + 1, y4 - y3 + 1, (x3 + y3) % 2 == 0)

	nblack -= b1
	nwhite += b1

	nwhite -= w2
	nblack += w2

	if intersect(x1,x2,x3,x4) and intersect(y1,y2,y3,y4):
		cw, cb = get(min(x2,x4) - max(x1,x3) + 1, min(y2,y4) - max(y1,y3) + 1, (max(x1,x3) + max(y1,y3)) % 2 == 0)
		nwhite -= cb
		nblack += cb

	print nwhite, nblack