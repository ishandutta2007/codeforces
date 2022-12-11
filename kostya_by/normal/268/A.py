n = int( input().split()[0] )
answer = 0
h = []
a = []
for i in range( 0, n ):
	team = input().split()
	h.append( int( team[0] ) )
	a.append( int( team[1] ) )
for i in range( 0, n ):
	for j in range( 0, n ):
		if i == j:
			continue
		if h[i] == a[j]:
			answer += 1
print( answer )