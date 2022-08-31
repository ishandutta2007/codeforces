a=[[0]*5]+[[0]+[x%2 for x in map(int,raw_input().split())]+[0]for i in range(3)]+[[0]*5]
for i in [1,2,3]:
	b=[]
	for j in [1,2,3]:
		b.append(str(1-(a[i-1][j]+a[i][j-1]+a[i][j]+a[i][j+1]+a[i+1][j])%2))
	print b[0]+b[1]+b[2]