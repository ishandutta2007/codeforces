R=lambda:map(int,raw_input().split())
n,m=R()
a=[0,0]
for x in R():a[0 if x<0 else 1]+=1
for i in range(m):
	x,y=R()
	print int(min(a)*2>=y-x+1 and (y-x)%2)