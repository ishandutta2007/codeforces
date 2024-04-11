class Solver1637A:

    def __init__(self):
        self.n = int(input())
        self.inp = list(map(int, input().split(' ')))

    def solve(self):
        for i in range(1, self.n):
            if self.inp[i-1] > self.inp[i]:
                return "YES"

        return "NO"

t = int(input())

while t:

    t -= 1

    cur = Solver1637A()

    print(cur.solve())