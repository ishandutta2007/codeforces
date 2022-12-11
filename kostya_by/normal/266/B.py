import copy

def process( s ):
	res = s[:]
	for i in range( 1, len(s) ):
		if s[i] == 'G' and s[i - 1] == 'B':
			res[i], res[i - 1] = res[i - 1], res[i]
	return res

fl = input().split()
n = int( fl[0] )
t = int( fl[1] )
s = input().split()[0]
S = []
for i in range(n):
	S.append( s[i] )
for i in range(t):
	S = process( S )
ans = ""
for i in range(n):
	ans += S[i]
print( ans )