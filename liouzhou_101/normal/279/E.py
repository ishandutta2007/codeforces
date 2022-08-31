x,y=0,1
for i in raw_input():
	p=min(x,y)+1
	if i=='0':y=p
	else:x=p
print x