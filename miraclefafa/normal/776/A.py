a,b=raw_input().split()
n=input()
print a,b
for i in xrange(n):
	c,d=raw_input().split()
	if a==c: a=d
	elif a==d: a=c
	elif b==c: b=d
	elif b==d: b=c
	print a,b