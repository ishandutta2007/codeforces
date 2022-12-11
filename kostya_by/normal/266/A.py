n = int( input().split()[0] )
s = input().split()[0]
c = 'A'
answer = 0
for i in range( 0, len( s ) ):
	if s[i] != c:
		answer += 1
	c = s[i]
print( n - answer )