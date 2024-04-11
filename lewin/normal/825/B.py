def ok(g):
	dx = [[0,0,0,0,0], [0,1,2,3,4], [0,1,2,3,4], [4,3,2,1,0]]
	dy = [[0,1,2,3,4], [0,0,0,0,0], [0,1,2,3,4], [0,1,2,3,4]]
	for i in range(10):
		for j in range(10):
			for b in range(len(dx)):
				ok = True
				for k in range(5):
					if not (0<=i+dx[b][k]<=9 and 0<=j+dy[b][k]<=9 and g[i+dx[b][k]][j+dy[b][k]] == 'X'):
						ok = False
				if ok:
					return True


f = [raw_input().rstrip() for __ in xrange(10)]

import sys
for i in range(10):
	for j in range(10):
		if f[i][j] == '.':
			f[i] = f[i][:j] + 'X' + f[i][j+1:]
			if ok(f):
				print "YES"
				sys.exit(0)
			f[i] = f[i][:j] + '.' + f[i][j+1:]

print "NO"