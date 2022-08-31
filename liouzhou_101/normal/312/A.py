for _ in range(input()):
	s=raw_input()
	a=s[-5:]=="lala."
	b=s[:5]=="miao."
	print "Freda's" if a and b==0 else "Rainbow's" if a==0 and b else "OMG>.< I don't know!"