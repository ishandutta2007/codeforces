n = int(input())
arr = list(map(int, input().split()))

n25, n50 = 0, 0

for x in arr:
	if (x == 25):
		n25 = n25 + 1
	if (x == 50):
		n50 = n50 + 1
		n25 = n25 - 1
	if (x == 100):
		if (n50 > 0):
			n50 = n50 - 1
			n25 = n25 - 1
		else:
			n25 = n25 - 3
	if (n25 < 0 or n50 < 0):
		print("NO")
		exit()

print("YES")