n, m = map(int, input().split())

pairs = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47]

for i in range(len(pairs) - 1):
	if n == pairs[i] and m == pairs[i + 1]:
		print("YES")
		exit()

print("NO")