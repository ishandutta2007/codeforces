fac=[1]
for i in xrange(1,101):
	fac.append(fac[i-1]*i)
s=[]
wall=[]
def ff(r,c,x):
	for p in xrange(1,c):
		s.append([fac[p+r-1]/fac[p]/fac[r-1],[x,49-p,x+1,49-p]])
	for q in xrange(r):
		s.append([fac[q+c-1]/fac[q]/fac[c-1],[x+r-q,1,x+r-q,2]])
ff(23,48,1)
ff(9,48,25)
ff(3,48,35)
for i in xrange(2,49):
	wall.append([24,i,25,i])
	wall.append([34,i,35,i])
T=input()
if T<=10:
	print T,2
	print 0
	exit(0)
T-=3
s.sort()
s.reverse()
for p in s:
	if T<p[0]: wall.append(p[1])
	else: T-=p[0]
n,m=38,49
print n,m
print len(wall)
for p in wall:
	print p[0],p[1],p[2],p[3]
#assert T==0
dp=[[0 for i in xrange(0,55)] for j in xrange(0,55)]
dp[1][1]=1
for i in xrange(1,n+1):
	for j in xrange(1,m+1):
		if i<n and not [i,j,i+1,j] in wall:
			dp[i+1][j]+=dp[i][j]
		if j<m and not [i,j,i,j+1] in wall:
			dp[i][j+1]+=dp[i][j]
#print dp[n][m]