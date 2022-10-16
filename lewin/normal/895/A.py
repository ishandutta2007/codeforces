n = int(raw_input())

arr = map(int, raw_input().split())

ans = 360
for i in range(n):
	s = 0
	for j in range(i,n):
		s += arr[j]
		ans = min(ans, abs(s - (360 - s)))
print ans