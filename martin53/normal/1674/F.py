import sys

input = sys.stdin.readline

def is_in(x1, y1, x2, y2):

    if y1 < y2:
        return 1
    if y1 == y2 and x1 <= x2:
        return 1
    return 0


class Solver1674F:

    def __init__(self):
        self.n, self.m, self.q = list(map(int, input().split(' ')))

        self.inp = []

        for i in range(self.n):
            cur = input()

            self.inp.append([0 for _ in range(self.m)])

            for j in range(self.m):
                if cur[j] == '.':
                    self.inp[i][j] = 0
                else:
                    self.inp[i][j] = 1

        self.x = self.n-1
        self.y = -1

        self.SZ = 0
        self.ones = 0

    def add(self, x, y):
        self.SZ += 1

        self.inp[x][y] = 1

        if is_in(x, y, self.x, self.y):
            self.ones += 1

        if self.x == self.n-1:
            self.y += 1
            self.x = 0
        else:
            self.x += 1

        if self.inp[self.x][self.y]:
            self.ones += 1

    def sub(self, x, y):
        self.SZ -= 1

        if self.inp[self.x][self.y]:
            self.ones -= 1

        if self.x == 0:
            self.y -= 1
            self.x = self.n-1
        else:
            self.x -= 1

        if is_in(x, y, self.x, self.y):
            self.ones -= 1

        self.inp[x][y] = 0

    def solve(self):
        for j in range(self.m):
            for i in range(self.n):
                if self.inp[i][j]:
                    self.inp[i][j] = 0
                    self.add(i, j)

        while self.q:
            self.q -= 1

            x, y = list(map(int, input().split(' ')))

            x -= 1
            y -= 1

            if self.inp[x][y] == 0:
                self.add(x, y)
            else:
                self.sub(x, y)

            print(self.SZ-self.ones)


cur = Solver1674F()

cur.solve()