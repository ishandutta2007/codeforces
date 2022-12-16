class Solver1654A:

    def __init__(self):
        self.n = int(input())
        self.inp = list(map(int, input().split(' ')))

    def solve(self):
        self.inp.sort()
        return self.inp[self.n-1]+self.inp[self.n-2]

t = int(input())

while t:

    t -= 1

    cur = Solver1654A()

    print(cur.solve())