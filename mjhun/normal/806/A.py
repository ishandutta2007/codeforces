def gcd(a,b):
	while b:
		a,b=b,a%b
	return a

def red(a,b):
	g=gcd(a,b)
	a/=g
	b/=g
	return (a,b)

tn=int(raw_input())



while tn>0:
	tn-=1
	x,y,p,q=map(int,raw_input().split())
	if p==q:
		if x==y:
			print 0
		else:
			print -1
		continue
	if p==0:
		if x==0:
			print 0
		else:
			print -1
		continue
	p,q=red(p,q)
	r=0
	z=x*q-p*y
	if z<0:
		a=(-z+q-p-1)/(q-p)
		x+=a
		y+=a
		r+=a
	elif z>0:
		a=(z+p-1)/p
		y+=a
		r+=a
	yy=((y+q-1)/q)*q
	r+=yy-y
	#print 'a',yy
	#y=yy
	#xx=(p*y)/q
	#r+=xx-x
	#x=xx
	#print x,y
	'''
	while 1:
		#print x,y
		z=x*q-p*y
		if z==0:
			break
		if z>0:
			a=(z+p-1)/p
			y+=a
			r+=a
		else:
			a=(-z+q-p-1)/(q-p)
			x+=a
			y+=a
			r+=a
	'''
	print r