from sys import stdout
from queue import Queue
t = int(input())
for _ in range(t):
	n = int(input())
	G = [[] for i in range(n)]
	for i in range(n - 1):
		v, u = map(int, input().split())
		v -= 1; u -= 1;
		G[v].append(u)
		G[u].append(v)

	def find_root():
		q = Queue()
		dist = [2 * n] * n
		dist[0] = 0
		q.put(0)
		while not q.empty():
			v = q.get()
			for u in G[v]:
				if dist[u] > dist[v] + 1:
					dist[u] = dist[v] + 1
					q.put(u)
		mx = max(dist)
		start = -1
		for i in range(n):
			if dist[i] == mx:
				start = i
				break
		q = Queue()
		dist = [2 * n] * n
		parent = [-1] * n
		dist[start] = 0
		q.put(start)
		while not q.empty():
			v = q.get()
			for u in G[v]:
				if dist[u] > dist[v] + 1:
					dist[u] = dist[v] + 1
					parent[u] = v
					q.put(u)
		mx = max(dist)
		finish = -1
		for i in range(n):
			if dist[i] == mx:
				finish = i
				break
		path = []
		while finish != start:
			path.append(finish)
			finish = parent[finish]
		path.append(start)
		return path[len(path) // 2]

	def dfs(v, pr):
		for u in G[v]:
			if (u != pr):
				dep[u] = dep[v] + 1
				dfs(u, v)

	dep = [0] * n
	dfs(find_root(), -1)
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