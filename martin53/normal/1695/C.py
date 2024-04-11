import sys

fast_input = sys.stdin.readline


class Solver1695C:

    def __init__(self):
        self.n, self.m = list(map(int, fast_input().split(' ')))
        self.inp = []
        for i in range(self.n):
            self.inp.append(list(map(int, fast_input().split(' '))))

    def solve(self):
        if (self.n + self.m) % 2 == 0:
            return "NO"

        dp_min = [[(self.n+self.m) for _ in range(self.m)] for _ in range(self.n)]

        for i in range(self.n):
            for j in range(self.m):
                if i > 0:
                    dp_min[i][j] = min(dp_min[i-1][j], dp_min[i][j])
                if j > 0:
                    dp_min[i][j] = min(dp_min[i][j-1], dp_min[i][j])

                if i == 0 and j == 0:
                    dp_min[i][j] = 0

                dp_min[i][j] += self.inp[i][j]

        dp_max = [[-(self.n + self.m) for _ in range(self.m)] for _ in range(self.n)]

        for i in range(self.n):
            for j in range(self.m):
                if i > 0:
                    dp_max[i][j] = max(dp_max[i - 1][j], dp_max[i][j])
                if j > 0:
                    dp_max[i][j] = max(dp_max[i][j - 1], dp_max[i][j])

                if i == 0 and j == 0:
                    dp_max[i][j] = 0

                dp_max[i][j] += self.inp[i][j]

        if dp_min[self.n-1][self.m-1] <= 0 and dp_max[self.n-1][self.m-1] >= 0:
            return "YES"

        return "NO"


t = int(input())

while t:

    t -= 1

    cur = Solver1695C()

    print(cur.solve())