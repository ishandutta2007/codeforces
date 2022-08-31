f=raw_input()
x=int(f[:-1])-1
y=x
r=f[-1]
if x%4>=2:
	x-=2
	y-=2
if x%4==0:
	x/=2
else:
	x=x/2+1
print x*6+[3,4,5,2,1,0][ord(r[0])-ord('a')]+y+1