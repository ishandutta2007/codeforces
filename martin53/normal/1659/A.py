class Solver1659A:

    def __init__(self):
        self.n, self.r, self.b = list(map(int, input().split(' ')))

    def solve(self):
        for i in range(self.b+1):

            cur = self.r//(self.b+1)

            if i < self.r % (self.b+1):
                cur += 1

            for j in range(cur):
                print('R', end='')

            if i < self.b:
                print('B', end='')

        print()

t = int(input())

while t:
    t -= 1

    cur = Solver1659A()

    cur.solve()