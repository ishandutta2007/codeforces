#from math import max
k,n,w = map(int,input().split())
print( max( 0 , k * w * ( w + 1 ) // 2 - n ) )