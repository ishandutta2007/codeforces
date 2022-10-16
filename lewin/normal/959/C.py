n = int(raw_input())

if n <= 5:
	print "-1"
else:
	print "1 2\n2 3\n2 4\n4 5\n4 6"
	for i in range(7, n+1):
		print 4,i
for i in range(n-1):
	print (i+1),(i+2)