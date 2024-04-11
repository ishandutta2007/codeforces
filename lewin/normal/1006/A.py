n = int(raw_input())

arr = map(int, raw_input().split())

for i in xrange(n):
	if (arr[i] % 2 == 0):
		arr[i] -= 1

print " ".join(map(str, arr))