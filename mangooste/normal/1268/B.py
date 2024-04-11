from sys import stdin
n = int(stdin.readline())
a = list(map(int, stdin.readline().split()))
sum = sum(a)
cnt = 0
for i in range(n):
	if i % 2 == 0:
		cnt += a[i] // 2
	else:
		cnt += (a[i] + 1) // 2
print(min(cnt, sum - cnt))