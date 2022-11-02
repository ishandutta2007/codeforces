n = input()
cur = 2
for i in range(1, n + 1):
	print (i + 1) * (i + 1) * i - cur / i
	cur = (i + 1) * i