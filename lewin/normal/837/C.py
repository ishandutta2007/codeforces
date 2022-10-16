n,a,b = map(int, raw_input().split())

x,y = [],[]
for __ in xrange(n):
	p,q = map(int, raw_input().split())
	x.append(p)
	y.append(q)

best = 0
for i in range(n):
	for j in range(i+1,n):
		ok = False
		if x[i]+x[j] <= a and y[i] <= b and y[j] <= b:
			ok = True
		if x[i]+y[j] <= a and y[i] <= b and x[j] <= b:
			ok = True
		if y[i]+x[j] <= a and x[i] <= b and y[j] <= b:
			ok = True
		if y[i]+y[j] <= a and x[i] <= b and x[j] <= b:
			ok = True
		if x[i]+x[j] <= b and y[i] <= a and y[j] <= a:
			ok = True
		if x[i]+y[j] <= b and y[i] <= a and x[j] <= a:
			ok = True
		if y[i]+x[j] <= b and x[i] <= a and y[j] <= a:
			ok = True
		if y[i]+y[j] <= b and x[i] <= a and x[j] <= a:
			ok = True
		if ok:
			best = max(best, x[i]*y[i]+x[j]*y[j])


print best