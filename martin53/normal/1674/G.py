class Solver1674G:

    def __init__(self):
        self.n, self.m = list(map(int, input().split(' ')))

        self.adj = [[] for _ in range(self.n)]

        self.in_degree = [0 for _ in range(self.n)]
        self.out_degree = [0 for _ in range(self.n)]

        for i in range(self.m):
            u, v = list(map(int, input().split(' ')))

            u -= 1
            v -= 1

            self.adj[u].append(v)
            self.in_degree[v] += 1
            self.out_degree[u] += 1

    def solve(self):
        queue = []

        degree = self.in_degree.copy()

        for i in range(self.n):
            if degree[i] == 0:
                queue.append(i)

        pointer = 0

        order = []

        while pointer < len(queue):
            node = queue[pointer]

            order.append(node)

            pointer += 1

            for j in self.adj[node]:
                degree[j] -= 1
                if degree[j] == 0:
                    queue.append(j)

        dp = [1 for _ in range(self.n)]

        for i in range(self.n-1, -1, -1):
            node = order[i]

            for j in self.adj[node]:
                if self.out_degree[node] != 1 and self.in_degree[j] != 1:
                    dp[node] = max(dp[node], dp[j]+1)

        return max(dp)


cur = Solver1674G()

print(cur.solve())