# -*- coding: utf-8 -*-
n=int(input())
a=[]
s=input()
for i in range(1000):
	a.append(0)
for i in range(len(s)-1):
	num=(ord(s[i])-ord('A'))*26+(ord(s[i+1])-ord('A'))
	a[num]=a[num]+1
maxx=0
for i in range(1000):
	maxx=max(maxx,a[i])
for i in range(1000):
	if maxx==a[i]:
		num1=i%26
		num2=i/26
		ans=chr(int(num2)+ord('A'))+chr(int(num1)+ord('A'))
	
print(ans)