t = int(input())

for _ in range(t):
	n = int(input())
	s = int(input())
	if(str(s)[0]!='9'):
		print(10**n-1-s)
	else:
		print((10**(n+1)-1)//9-s)