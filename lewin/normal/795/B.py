n,m,d = map(int, raw_input().split())
pp = []
for _ in range(n):
	x,y = map(int, raw_input().split())
	pp.append((-x,y))
ip = []
for _ in range(m):
	x,y = map(int, raw_input().split())
	ip.append((-x,y))


pp = sorted(pp)
ip = sorted(ip)

cur = 0
front = 0
cwidth = 0
for i in range(n):
	if pp[i][1] + cwidth > d:
		break
	front += 1
	cwidth += pp[i][1]
	cur -= pp[i][0]

best = 0
for i in range(m):
	cwidth += ip[i][1]
	cur -= ip[i][0]
	while front > 0 and cwidth > d:
		cwidth -= pp[front-1][1]
		cur += pp[front-1][0]
		front -= 1
	if front == 0 or cwidth > d:
		break
	best = max(best, cur)

print best