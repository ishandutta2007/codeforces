

class solver1680B:

    def __init__(self):
        self.n, self.m = list(map(int, input().split(' ')))

        self.inp = []

        for i in range(0, self.n):
            self.inp.append(input())

    def solve(self):
        x_mini = self.n-1
        y_mini = self.m-1

        for i in range(0, self.n):
            for j in range(0, self.m):
                if self.inp[i][j] == 'R':
                    x_mini = min(x_mini, i)
                    y_mini = min(y_mini, j)

        if self.inp[x_mini][y_mini] == 'R':
            return "YES"
        return "NO"


t = int(input())

while t:
    t = t - 1

    cur = solver1680B()

    print(cur.solve())