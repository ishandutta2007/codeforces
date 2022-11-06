import math

# cin = open( "input.txt", 'r' )	
# a = cin.read()
a = input()
cur = ord( 'a' )
ans = int( 0 )
for i in a:
	ans += min( abs( cur - ord( i ) ), abs( cur + 26 - ord( i ) ), abs( cur - 26 - ord( i ) ) )
	cur = ord( i )
print( ans )