s,v1,v2,t1,t2 = map(int, raw_input().split())

if v1 * s + t1 * 2 == v2 * s + t2 * 2:
	print "Friendship"
elif v1 * s + t1 * 2 < v2 * s + t2 * 2:
	print "First"
else:
	print "Second"