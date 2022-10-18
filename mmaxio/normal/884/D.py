r = lambda: map(int, input().split())

import heapq

def main():
	n, = r()
	a = list(r())
	if len(a) % 2 == 0:
		a.append(0)
	heapq.heapify(a)
	ret = 0
	while len(a) > 1:
		x = heapq.heappop(a)
		y = heapq.heappop(a)
		z = heapq.heappop(a)
		ret += x + y + z
		heapq.heappush(a, x + y + z)
	print(ret)

main()