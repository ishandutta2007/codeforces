r = lambda: map(int, input().split())

n, = r()
a = sorted(tuple(r()) for _ in range(n))[::-1]

ret, left = 0, 10**9 + 1
for l, r in a:
	if r < left:
		ret += 1
		left = l

print(ret)