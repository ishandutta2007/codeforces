s=raw_input()

n=len(s)

flip=0

ans=[0] * n

for i in xrange(n - 1, -1, -1):
	if s[i] == 'a':
		ans[i] = 1 - flip
		flip = 1
	else:
		ans[i] = flip
		flip = 0

print " ".join(map(str, ans))