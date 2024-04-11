# -*- coding: utf-8 -*-
n,k=input().split()
n=int(n)
k=int(k)
while k:
	if n%10==0:
		n/=10
	else :
		n-=1
	k-=1
print(int(n))