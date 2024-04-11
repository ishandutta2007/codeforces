def g(x):
	return x*(x+1)/2

def f(x,h):
	if x<=h:
		return g(x)
	return g(h+(x-h)/2)-g(h-1)+g(h+(x-h-1)/2)

n,h=map(int,raw_input().split())
s=1
e=10**18
while e-s>1:
	m=(s+e)/2
	if f(m-1,h)>=n:
		e=m
	else:
		s=m
print s