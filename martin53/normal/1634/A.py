class Solver1634A:

    def __init__(self):
        self.n, self.k = list(map(int, input().split(' ')))
        self.inp = input()

    def solve(self):
        if self.k == 0:
            return 1

        if self.inp == self.inp[::-1]:
            return 1

        return 2


t = int(input())

while t:

    t -= 1

    cur = Solver1634A()

    print(cur.solve())