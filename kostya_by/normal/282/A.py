n = int( input().split()[0] )
x = 0
for i in range( 0, n ):
	s = input().split()[0]
	if s[1] == '+':
		x += 1
	else:
		x -= 1
print( x )