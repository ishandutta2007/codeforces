class Solver1703B:

    def __init__(self):
        self.n = int(input())
        self.inp = input()

    def solve(self):

        dict = {}

        for j in self.inp:
            dict[j] = 1

        return len(self.inp)+len(dict)


t = int(input())

while t:

    t -= 1

    cur = Solver1703B()

    print(cur.solve())