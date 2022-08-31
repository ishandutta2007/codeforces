k=input()
l=input()
for x in range(40):
	if k**x==l:
		print "YES"
		print x-1
		exit()
print "NO"