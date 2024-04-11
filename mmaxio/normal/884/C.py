r = lambda: map(int, input().split())

def main():
	n, = r()
	p = [x - 1 for x in r()]
	vis = [False] * n
	lens = []
	for i in range(n):
		if vis[i]:
			continue
		vis[i], cc = True, 1
		j = p[i]
		while not vis[j]:
			vis[j] = True
			cc += 1
			j = p[j]
		lens.append(cc)
	lens.sort()
	if len(lens) > 1:
		lens[-2] += lens[-1]
		lens.pop()
	print(sum(x * x for x in lens))

main()