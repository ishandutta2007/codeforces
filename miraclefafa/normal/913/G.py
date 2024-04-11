from random import *
n=input()
#n=2000
bit=[1]
for j in xrange(30):
	bit.append(4*10**j)
val=[pow(2,w,10**30) for w in bit]
for i in xrange(n):
	a=input()
#	a=randint(10**10,10**11-1)
	r=(a*(10**12)+5*10**11)%(2**30)
	r=a*(10**12)+5*10**11-r
	while r%5==0:
		r+=2**30
	c=10000
	ret=pow(2,c,10**30)
	for j in xrange(30):
		mod=10**(j+1)
		for k in xrange(10):
			if ret%mod==r%mod:
				c+=bit[j]*k
				break
			ret=ret*val[j]
	print c
#	for j in xrange()