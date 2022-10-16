def f(n):
	if n == 3:
		return [[1,2,3],[1,2,3]]
	elif n == 4:
		return [[1,2,3,4],[1,2,4,3],[1,3,2,4]]
	else:
		return f(n-2) + [[n-1,n,1]] + [[n-1,n,n-2]] + [[n-1,i,n,i+1] for i in range(1,n-2)]

r = f(int(raw_input()))
print len(r)
for x in r:
	print len(x), " ".join(map(str,x))