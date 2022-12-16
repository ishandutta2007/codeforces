class Solver1708A:

    def __init__(self):
        self.n = int(input())
        self.inp = list(map(int, input().split(' ')))

    def solve(self):
        for j in self.inp:
            if j % self.inp[0] != 0:
                print('NO')
                return

        print('YES')

t = int(input())

while t:

    t -= 1

    cur = Solver1708A()

    cur.solve()