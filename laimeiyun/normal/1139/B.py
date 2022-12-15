n = input()
a = map(int, raw_input().split())

ans = 0
pos = 10 ** 10

for i in range(n-1,-1,-1):
	pos = max(min(pos - 1, a[i]), 0)
	ans += pos

print ans