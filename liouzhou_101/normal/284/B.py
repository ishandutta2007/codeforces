input()
s=raw_input()
if s.count("I")>1:
	print 0
elif s.count("I")==1:
	print 1
else:
	print s.count("A")