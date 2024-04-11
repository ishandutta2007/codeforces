# -*- coding: utf-8 -*-
n,k=input().split()
n=int(n)
k=int(k)
if k%n==0:
	print(k//n)
else:
	print(k//n+1)