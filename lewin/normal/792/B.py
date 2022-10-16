n,k = map(int, raw_input().split())
a = map(int, raw_input().split())
elim = [False for i in range(n)]
curnum = 0
for i in range(k):
	step = a[i] % (n - i)
	while step > 0:
		if not elim[curnum]:
			step -= 1
		curnum = (curnum + 1) % n
	while elim[curnum]:
		curnum = (curnum + 1) % n
	elim[curnum] = True
	print curnum + 1
	curnum = (curnum + 1) % n
	while elim[curnum]:
		curnum = (curnum + 1) % n