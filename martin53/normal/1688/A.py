class Solver1688A:

    def __init__(self):
        self.x = int(input())

    def solve(self):
        lowest = self.x & (-self.x)

        if lowest != self.x:
            return lowest

        if self.x == 1:
            return 3

        return self.x + 1


t = int(input())

while t:

    t -= 1

    cur = Solver1688A()

    print(cur.solve())