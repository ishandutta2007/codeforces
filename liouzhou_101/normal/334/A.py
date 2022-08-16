n=input()
for i in range(n):
	for j in range(n):print j*n+[i+1,n-i][j%2],
	print