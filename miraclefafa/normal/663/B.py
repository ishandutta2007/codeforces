_=input()
def query(c):
#	print c
	pre=0
	if len(c)==1:
		if int(c)>=9:
			pre=1989
		else:
			pre=1990+int(c)
	elif len(c)==2:
		if int(c)>=89:
			pre=1900+int(c)
		else:
			pre=2000+int(c)
	elif len(c)==3:
		if int(c)>=989:
			pre=1000+int(c)
		else:
			pre=2000+int(c)
	elif len(c)>=4:
		if c[0]=='0':
			pre=10**len(c)+int(c)
		elif int(c)>=1989:
			pre=int(c)
		else:
			pre=10**len(c)+int(c)
	while pre in p:
		pre+=10**len(c)
	return pre
for __ in xrange(_):
	s=raw_input()
	s=s[4:]
	p=[]
	for i in xrange(1,len(s)+1):
		y=query(s[-i:])
		p.append(y)
	print y