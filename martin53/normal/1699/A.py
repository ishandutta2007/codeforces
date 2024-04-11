class Solver1699A:

    def __init__(self):
        self.n = int(input())

    def solve(self):
        if self.n % 2 == 0:
            print(0, self.n//2, self.n//2)
        else:
            print(-1)

t = int(input())

while t:

    t -= 1

    cur = Solver1699A()

    cur.solve()