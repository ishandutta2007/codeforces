import sys

input = sys.stdin.readline


class Solver1694D:

    def __init__(self):
        self.n = int(input())
        self.parents = list(map(int, input().split(' ')))
        self.adj = [[] for _ in range(self.n)]

        for i in range(len(self.parents)):
            self.adj[self.parents[i]-1].append(i+1)

        self.l = []
        self.r = []

        for i in range(self.n):
            l, r = list(map(int, input().split(' ')))
            self.l.append(l)
            self.r.append(r)

        self.dp = [0 for _ in range(self.n)]

    def solve(self):
        output = 0

        for i in range(self.n-1, -1, -1):
            intake = 0

            for j in self.adj[i]:
                intake += self.dp[j]

            if intake < self.l[i]:
                output += 1
                self.dp[i] = self.r[i]
            else:
                self.dp[i] = min(self.r[i], intake)

        return output


t = int(input())

while t:

     t -= 1

     cur = Solver1694D()

     print(cur.solve())