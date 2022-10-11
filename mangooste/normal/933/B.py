p, k = map(int, input().split())
ans = []
while p != 0:
	ans.append(p % k)
	p //= k
	p *= -1
print(len(ans))
print(*ans)