from __future__ import print_function
import urllib2
import json
n = int( raw_input() )
a = map( int, raw_input().split() )
bal = 0
for i in range( n ):
    if ( a[i] % 2 == 0 ):
        bal += 1
    else:
        bal -= 1
for i in range( n ):
    if ( bal > 0 and a[i] % 2 == 1 ):
        print( i + 1 )
    if ( bal < 0 and a[i] % 2 == 0 ):
        print ( i + 1 )