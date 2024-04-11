n=input()
for i in range(n):
	p,q,b=map(int,raw_input().split())
	print['Finite','Infinite'][bool(p*pow(b,60,q)%q)]