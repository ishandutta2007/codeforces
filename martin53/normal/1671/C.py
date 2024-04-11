class Solver1671C:

    def __init__(self):
        self.n, self.x = list(map(int, input().split(' ')))
        self.inp = list(map(int, input().split(' ')))

    def solve(self):
        outp = 0

        self.inp.sort()

        for i in range(self.n):

            self.x -= self.inp[i]

            if self.x >= 0:
                outp += 1 + self.x//(i+1)

        return outp


t = int(input())

while t:

    t -= 1

    cur = Solver1671C()

    print(cur.solve())