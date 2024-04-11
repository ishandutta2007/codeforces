class Solver1697A:

    def __init__(self):
        self.n, self.m = list(map(int, input().split(' ')))
        self.inp = list(map(int, input().split(' ')))

    def solve(self):
        self.m -= sum(self.inp)

        return max(0, -self.m)


t = int(input())

while t:
    t -= 1

    cur = Solver1697A()

    print(cur.solve())