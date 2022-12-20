class Solver1675F:

    def __init__(self):

        self.n = input()

        self.n, self.k = list(map(int, input().split(' ')))
        self.x, self.y = list(map(int, input().split(' ')))

        self.go = list(map(int, input().split(' ')))

        self.adj = [[] for _ in range(self.n+1)]

        for i in range(1, self.n):
            u, v = list(map(int, input().split(' ')))
            self.adj[u].append(v)
            self.adj[v].append(u)

        self.order = [0 for _ in range(self.n+1)]
        self.parent = [0 for _ in range(self.n+1)]
        self.sum_tree = [0 for _ in range(self.n+1)]

    def solve(self):
        queue = [[self.x, self.x]]  #[node, parent]

        pointer = 0

        while pointer < len(queue):

            tp = queue[pointer]

            self.order[pointer] = tp[0]

            self.parent[tp[0]] = tp[1]

            pointer += 1

            for j in self.adj[tp[0]]:
                if j != tp[1]:
                    queue.append([j, tp[0]])

        self.sum_tree[self.y] = 1

        for j in self.go:
            self.sum_tree[j] = 1

        for i in range(self.n-1, -1, -1):
            node = self.order[i]

            for j in self.adj[node]:
                if j != self.parent[node]:
                    self.sum_tree[node] += self.sum_tree[j]

        outp = 0

        for i in range(self.n+1):
            if self.sum_tree[i] >= 1:
                outp += 2

        outp -= 2

        while self.y != self.x:
            outp -= 1
            self.y = self.parent[self.y]

        return outp


t = int(input())

while t:
    t -= 1

    cur = Solver1675F()

    print(cur.solve())