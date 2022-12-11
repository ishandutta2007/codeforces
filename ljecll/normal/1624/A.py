tc = int(input())

for t in range(tc):
	n = int(input())
	arr = list(map(int, input().split()))
	# print(arr)
	mx = arr[0]
	mn = arr[0]
	for i in range(n):
		if (arr[i] > mx):
			mx = arr[i]
		if (arr[i] < mn):
			mn = arr[i]
	print(mx - mn)