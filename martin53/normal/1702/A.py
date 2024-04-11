class Solver1702A:

    def __init__(self):
        self.n = int(input())

    def solve(self):
        for i in range(20):
            if 10**i > self.n:
                return self.n - (10**(i-1))

        return -1


t = int(input())

while t:

    t -= 1

    cur = Solver1702A()

    print(cur.solve())