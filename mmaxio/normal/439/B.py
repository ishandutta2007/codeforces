n, x = map(int, input().split())

c = sorted(list(map(int, input().split())))
ret = 0
for y in c:
	ret += x * y
	x = max(x - 1, 1)

print(ret)