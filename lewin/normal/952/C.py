n = int(raw_input())
arr = map(int, raw_input().split())
brr = sorted(arr)
for __ in xrange(100):
	for i in range(len(arr)-1):
		while arr[i] - arr[i+1] >= 2:
			arr[i] -= 1
			arr[i+1] += 1
		while arr[i+1] - arr[i] >= 2:
			arr[i+1] -= 1
			arr[i] += 1
ans = []
while len(arr) > 0:
	t = max(arr)
	ans.append(t)
	arr.remove(t)
	for __ in xrange(100):
		for i in range(len(arr)-1):
			while arr[i] - arr[i+1] >= 2:
				arr[i] -= 1
				arr[i+1] += 1
			while arr[i+1] - arr[i] >= 2:
				arr[i+1] -= 1
				arr[i] += 1

ans = ans[::-1]
print (ans == brr) * "YES" or "NO"