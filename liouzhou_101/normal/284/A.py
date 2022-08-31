p=input()
k=0
for x in range(1,p):
	u=0
	t=1
	for i in range(1,p-1):
		t=t*x%p
		if t==1:
			u=1
			break
	if u==0 and t*x%p==1:
		k+=1
print k