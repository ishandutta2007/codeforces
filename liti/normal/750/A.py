n, k = map(int, input().split())
a = [ i * (i+1) // 2 for i in range(1, n+1) ]
print( sum( map( lambda x : x <= (240 - k) // 5 , a ) ) )