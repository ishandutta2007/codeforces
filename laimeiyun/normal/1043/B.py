n = input()
a = [0] + map(int, raw_input().split())

gap = [0] * n
ans = []

for k in xrange(1, n + 1):
	t = 1
	for i in xrange(0, n):
		g = a[i + 1] - a[i]
		if i<k:
			gap[i] = g
		else:
			if gap[i % k]!=g:
				t = 0
				break
	if t == 1:
		ans.append(k)

print len(ans)
print " ".join(map(str, ans))