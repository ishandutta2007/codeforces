n = int(input())
sum = n * (n + 1) // 2
for x in map(int, input().split()):
	sum -= x

print(sum)