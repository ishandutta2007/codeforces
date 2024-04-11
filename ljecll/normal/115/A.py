n = int(input())
parent = [n] * n
edge = []
depth = [0] * n
ans = 0
stor = []

for i in range(n):
	edge.append([])
for i in range(n):
	parent[i] = int(input())
	parent[i] = parent[i] - 1
	if (parent[i] == -2):
		parent[i] = n
	else:
		edge[parent[i]].append(i)

for i in range(n):
	if (parent[i] != n):
		continue;
	stor = [i]
	while(stor):
		u = stor[-1]
		stor = stor[:-1]
		for v in edge[u]:
			depth[v] = depth[u] + 1
			stor.append(v)

for i in range(n):
	ans = max(ans, depth[i])

print(ans + 1)