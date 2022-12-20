class Solver1669B:

    def __init__(self):
        self.n = int(input())
        self.inp = list(map(int, input().split(' ')))

    def solve(self):
        self.inp.sort()

        for i in range(2, self.n, 1):
            if self.inp[i-2] == self.inp[i]:
                return self.inp[i]

        return -1

t = int(input())

while t:

    t -= 1

    cur = Solver1669B()

    print(cur.solve())