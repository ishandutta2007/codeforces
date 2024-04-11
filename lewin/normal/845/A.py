n = int(raw_input())
arr = sorted(map(int, raw_input().split()))
if arr[n] > arr[n-1]:
	print "YES"
else:
	print "NO"