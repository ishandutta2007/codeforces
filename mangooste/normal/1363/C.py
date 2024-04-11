t = int(input())
for _ in range(t):
	n, x = map(int, input().split())
	cnt = 0
	for _ in range(n - 1):
		v, u = map(int, input().split())
		if v == x or u == x:
			cnt += 1
	if (cnt <= 1):
		print("Ayush")
	else:
		print("Ayush" if n % 2 == 0 else "Ashish")