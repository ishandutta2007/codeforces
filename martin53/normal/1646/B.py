class Solver1646B:

    def __init__(self):
        self.n = int(input())
        self.inp = list(map(int, input().split(' ')))

    def solve(self):
        self.inp.sort()

        active = self.inp[0]

        for i in range(1, self.n):
            if i >= self.n - i:
                break

            active = active+self.inp[i]-self.inp[self.n-i]

            if active < 0:
                return "YES"

        return "NO"


t = int(input())

while t:

    t -= 1

    cur = Solver1646B()

    print(cur.solve())