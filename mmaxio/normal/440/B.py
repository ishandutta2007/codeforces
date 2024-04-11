import itertools

n = int(input())

a = map(int, input().split())
a = list(itertools.accumulate(a))

need_one = a[-1] // n

ans = 0
for i in range(len(a) - 1):
	ans += abs((i + 1) * need_one - a[i])

print(ans)