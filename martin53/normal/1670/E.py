import sys

input = sys.stdin.readline


class Solver1670E:

    def __init__(self):
        self.p = int(input())
        self.n = (1 << self.p)
        self.adj = [[] for _ in range(self.n+1)]

        for i in range(self.n-1):
            u, v = list(map(int, input().split(' ')))

            u -= 1
            v -= 1

            self.adj[u].append([v, i])  #[node, id]
            self.adj[v].append([u, i])

        self.output = [0 for _ in range(self.n)]
        self.output_edges = [0 for _ in range(self.n-1)]

        self.mem_xors = [0 for _ in range(self.n)]

    def solve(self):

        self.output[0] = self.n

        self.mem_xors[0] = self.n

        queue = [[0, 0]]  #[node, parent]

        pointer = 0

        other = 1

        while pointer < len(queue):
            tp = queue[pointer]

            pointer += 1

            for j in self.adj[tp[0]]:

                if j[0] != tp[1]:

                    queue.append([j[0], tp[0]])

                    if self.mem_xors[tp[0]] == 0:
                        self.output_edges[j[1]] = other
                        self.output[j[0]] = other+self.n
                    else:
                        self.output_edges[j[1]] = other+self.n
                        self.output[j[0]] = other

                    self.mem_xors[j[0]] = self.n-self.mem_xors[tp[0]]

                    other += 1

        print("1")
        print(' '.join(map(str, self.output)))
        print(' '.join(map(str, self.output_edges)))


t = int(input())

while t:
    t -= 1

    cur = Solver1670E()

    cur.solve()