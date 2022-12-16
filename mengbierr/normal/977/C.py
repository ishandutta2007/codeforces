# -*- coding: utf-8 -*-
n,k=input().split()
n=int(n)
k=int(k)
a=[int(i) for i in input().split()]
a.sort()
num=a[k-1]
ans=0
for i in a:
	if i<=num:
		ans+=1
if k==0:
	num=a[0]-1
	ans=0
	if num<=0:
		print(-1)
		exit()
if ans!=k:
	print(-1)
else:
	print(num)