from sys import stdout, stdin

def f (k, m):
	x, s, res = 1, 1, 0
	while x <= m:
		if x * 10 - 1 <= m:
			res += k * s * (x * 10 - x)
		else:
			res += k * s * (m - x + 1)
		s += 1
		x *= 10
	return res

def obtRes (w, n, k):
	i, j, rep = n, n+w+1, 60
	while rep > 0:
		m = (i+j)/2
		if f(k, m) - f(k, n-1) <= w:
			i = m
		else:
			j = m
		rep -= 1
	if f(k, i) - f(k, i-1) <= w:
		return i - n + 1
	return 0

w, n, k = (int(i) for i in stdin.readline().split())
stdout.write(str(obtRes(w, n, k))+'\n')