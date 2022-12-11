b, k = map(int, input().split())
arr = list(map(int, input().split()))
sum = 0

if b % 2 == 1:
	for x in arr:
		sum += x
else:
	sum = arr[-1]
if sum % 2 == 1:
	print("odd")
else:
	print("even")