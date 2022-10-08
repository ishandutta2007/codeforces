s = raw_input()
n = len(s)
pb = -1
for i in xrange(n):
	if s[i] == 'B':
		pb = i

if pb != -1:
	s = s[pb:] + s[:pb]

s = s[-1] + s + s[0]

res = 1

dp = []

for i in xrange(n + 2):
	dp.append([[[0, 0], [0, 0]], [[0, 0], [0, 0]]])

for i in xrange(2, n + 1):
	for first in xrange(2):
		for prev in xrange(2):
			for last in xrange(2):
				for cur in xrange(2):
					if s[i - 1:i + 1] != 'BA' and cur == 1:
						continue
					if i == 2:
						if first != cur or prev != 0 or last != 0:
							continue
						dp[i][first][last][cur] = 1
					elif i > 2:
						if s[i - 2:i] == 'AB' and prev == 0 and cur == 0:
							continue
						if i == n and s[n] + s[1] == 'AB' and cur == 0 and first == 0:
							continue
						if i == n and s[n - 1:n + 1] == 'AB' and cur == 0 and last == 0:
							continue
						dp[i][first][last][cur] += dp[i - 1][first][prev][last]

res = 0
for i in xrange(2):
	for j in xrange(2):
		for k in xrange(2):
			res += dp[n][i][j][k]

print res