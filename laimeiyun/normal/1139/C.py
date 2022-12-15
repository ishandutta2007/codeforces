import sys

n, k = map(int, raw_input().split())
f = [i for i in range(n + 1)]
s = [1 for i in range(n + 1)]

def parent(x):
	if f[x] == x:
		return x
	else:
		y = parent(f[x])
		f[x] = y
		return y

sys.setrecursionlimit(10 ** 6)

for i in range(1, n):
	p, q, r = map(int, raw_input().split())
	if r == 1:
		continue
	p = parent(p)
	q = parent(q)
	if s[p] < s[q]:
		p, q = q, p
	f[q] = p
	s[p] += s[q]

ans = pow(n, k, 10 ** 9 + 7)

for i in range(1, n + 1):
	if parent(i) == i:
		ans = ans + 10 ** 9 + 7 - pow(s[i], k, 10 ** 9 + 7)

ans %= 10 ** 9 + 7
print ans