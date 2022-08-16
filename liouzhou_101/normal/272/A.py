n=input()
a=sum(map(int,raw_input().split()))
p=0
for i in range(1,6):
	if (a+i)%(n+1)!=1:
		p+=1
print p