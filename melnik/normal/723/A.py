import math
# cin = open( "input.txt", 'r' )	
# a = list( map ( int, cin.read().split() ) )
a = list( map ( int, input().split() ) )
a.sort()
print( abs( a[1] - a[0] ) + abs( a[1] - a[2] ) )