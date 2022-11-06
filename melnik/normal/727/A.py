import math

a = []

def dfs( pos, need ):
	x = a[pos]
	# print( x )
	if x > need:
		return
	if x == need:
		print( "YES" )
		print( pos + 1 )
		print( *a )
		# for i in a:
		# 	print( i )
		exit( 0 )
	a.append( x * 2 )
	dfs( pos + 1, need )
	a.pop()
	a.append( 10 * x + 1 )
	dfs( pos + 1, need )
	a.pop()


# cin = open( "input.txt", 'r' )	
# x, y = map( int, cin.read().split() )
x, y = map( int, input().split() )
a = [ x ]
dfs( 0, y )
print( "NO" )