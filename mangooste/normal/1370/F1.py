from sys import stdout
from queue import Queue
import random
t = int(input())
for _ in range(t):
	n = int(input())
	G = [[] for i in range(n)]
	for i in range(n - 1):
		v, u = map(int, input().split())
		v -= 1; u -= 1;
		G[v].append(u)
		G[u].append(v)
	dep = [0] * n

	def dfs(v, pr):
		for u in G[v]:
			if (u != pr):
				dep[u] = dep[v] + 1
				dfs(u, v)

	dfs(random.randint(0, n - 1), -1)
	print("?", n, *list(range(1, n + 1)))
	stdout.flush()
	tmp, dist = map(int, input().split())
	max_dep = max(dep)
	v = 0
	R = max_dep + 1; L = 0
	while R - L > 1:
		mid = (L + R) // 2
		vers = []
		for i in range(n):
			if dep[i] >= mid:
				vers.append(i + 1)
		print("?", len(vers), *vers)
		stdout.flush()
		tmp, cur_dist = map(int, input().split())
		if cur_dist == dist:
			L = mid
			v = tmp
		else:
			R = mid
	v -= 1
	q = Queue()
	dist_v = [2 * n] * n
	dist_v[v] = 0
	q.put(v)
	while not q.empty():
		cur = q.get()
		for u in G[cur]:
			if dist_v[u] > dist_v[cur] + 1:
				dist_v[u] = dist_v[cur] + 1
				q.put(u)
	vers = []
	for i in range(n):
		if dist_v[i] == dist:
			vers.append(i + 1)
	print("?", len(vers), *vers)
	stdout.flush()
	u, tmp = map(int, input().split())
	u -= 1
	print("!", u + 1, v + 1)
	stdout.flush()
	tmp = input()