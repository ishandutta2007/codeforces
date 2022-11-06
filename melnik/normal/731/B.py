import math

def Bad():
	print( "NO" )
	exit( 0 )

# cin = open( "input.txt", 'r' )	
# n = int( cin.readline() )
# a = list( map( int, cin.read().split() ) )
n = int( input() )
a = list( map( int, input().split() ) )
haveNow = False
for i in range ( n ):
	if haveNow:
		a[i] -= 1
		haveNow = False
	if a[i] < 0:
		Bad()
	a[i] %= 2
	if a[i]:
		haveNow = True
if haveNow:
	Bad()
print( "YES" )