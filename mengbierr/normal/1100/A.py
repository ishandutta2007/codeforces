# -*- coding: utf-8 -*-
n,k=(int(s)for s in input().split(' '))
a=[int(s)for s in input().split(' ')]
sum=0
for i in range(n):
	sum+=a[i]
ans=0
for i in range(k):
	sum1=sum
	for j in range(i,n,k):
		sum1-=a[j]
	ans=max(ans,abs(sum1))
print(ans)