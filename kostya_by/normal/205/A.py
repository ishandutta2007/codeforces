import copy

n = int( input() )
inp = input().split()
a = []
for i in range(n):
	a.append( int( inp[i] ) )
b = copy.deepcopy( a )
a.sort()
if n >= 2 and a[0] == a[1]:
	print( "Still Rozdil" )
else:
	for i in range( n ):
		if b[i] == a[0]:
			print( i + 1 )