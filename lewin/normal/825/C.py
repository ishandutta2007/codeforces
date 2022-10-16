n,k = map(int, raw_input().split())
arr = sorted(map(int, raw_input().split()))

maxd = k

count = 0
for x in arr:
	while 2 * maxd < x:
		count += 1
		maxd *= 2
	maxd = max(maxd, x)

print count