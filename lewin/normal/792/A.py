n = int(raw_input())
a = sorted(map(int, raw_input().split()))
diff = a[1]-a[0]
count = 0
for i in range(1,n):
	if a[i]-a[i-1] < diff:
		diff = a[i]-a[i-1]
		count = 0
	if a[i]-a[i-1] == diff:
		count += 1
print diff,count