class Solver1692C:

    def __init__(self):
        input()

        self.n = 8

        self.inp = [[] for _ in range(self.n)]

        for i in range(self.n):
            self.inp[i] = input()

    def solve(self):
        for i in range(1, self.n-1):
            for j in range(1, self.n-1):
                if self.inp[i-1][j-1] == '#' and self.inp[i-1][j+1] == '#' and self.inp[i][j] == '#' and self.inp[i+1][j-1] == '#' and self.inp[i+1][j+1] == '#':
                    print(i+1, j+1)
                    return


t = int(input())

while t:
    t -= 1

    cur = Solver1692C()

    cur.solve()