from collections import defaultdict, deque
n,m = map(int, raw_input().split())

e = map(int, raw_input().split())

deg = [0 for __ in xrange(n)]


graph = defaultdict(list)
for i in xrange(m):
	a,b = map(int, raw_input().split())
	graph[a].append(b)
	deg[b] += 1

queue1 = deque([])
queue2 = deque([])
for i in xrange(n):
	if deg[i] == 0:
		if e[i] == 1:
			queue2.append(i)
		else:
			queue1.append(i)

ans = 0
while len(queue1) > 0 or len(queue2) > 0:
	# main process
	while len(queue1) > 0:
		x = queue1.popleft()
		for b in graph[x]:
			deg[b] -= 1
			if deg[b] == 0:
				if e[b] == 1:
					queue2.append(b)
				else:
					queue1.append(b)

	# coprocessor
	ans += len(queue2) > 0
	while len(queue2) > 0:
		x = queue2.popleft()
		for b in graph[x]:
			deg[b] -= 1
			if deg[b] == 0:
				if e[b] == 1:
					queue2.append(b)
				else:
					queue1.append(b)

print ans