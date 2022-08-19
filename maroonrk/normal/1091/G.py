#!/usr/local/bin/pypy3

import math
import random

n=int(input())

ls=[n]

for step in range(20):
	x=random.randint(1,n-1)
	print('sqrt',x*x%n)
	y=int(input())
	
	tmp=[]
	
	z=(x+y)%n
	for v in ls:
		g=math.gcd(v,z)
		tmp.append(g)
		tmp.append(v//g)
	
	z=(x-y)%n
	for v in ls:
		g=math.gcd(v,z)
		tmp.append(g)
		tmp.append(v//g)
	
	ls=list(set(tmp))

ls.remove(1)
print('!',len(ls),*ls)