t = int(input())
for _ in range(t):
	n, x = map(int, input().split())
	a = list(map(int, input().split()))
	odd = 0; even = 0
	for el in a:
		if (el % 2 == 1):
			odd += 1
		else:
			even += 1
	ok = 0
	for i in range(odd + 1):
		if i % 2 == 1 and i <= x and x - i <= even:
			ok = 1
	print("YES" if ok else "NO")