class Solver1634B:

    def __init__(self):
        self.n, self.x, self.y = list(map(int, input().split(' ')))
        self.inp = list(map(int, input().split(' ')))

    def solve(self):
        if (sum(self.inp) + self.x) % 2 == self.y % 2:
            return 'Alice'

        return 'Bob'

t = int(input())

while t:

    t -= 1

    cur = Solver1634B()

    print(cur.solve())