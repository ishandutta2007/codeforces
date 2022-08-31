n=input()
A=B=0
for i in range(n):
	a,b=map(int,raw_input().split())
	A+=a
	B+=b
print min(A,n-A)+min(B,n-B)