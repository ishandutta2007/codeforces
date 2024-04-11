from __future__ import print_function
import urllib2
import json
s = raw_input()
n = len( s )
i = 0
a = False
b = False
while ( i < n ):
    if i + 2 < n and s[i] == 'W' and s[i + 1] == 'U' and s[i + 2] == 'B':
        i += 3
        a = True
    else:
        if a == True and b == True:
            print("", end=" ")
        a = False
        print( s[i], end = "" )
        b = True
        i += 1