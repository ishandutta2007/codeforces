n = int(raw_input())

def s(w):
	return sum(map(int,str(w)))

res = []
for sumdig in range(0,min(n,1000)+1):
	x = n - sumdig
	if (x + s(x)) == n:
		res.append(x)

print len(res)
res = sorted(res)
for g in res: print g