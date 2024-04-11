class Solver1668B:

    def __init__(self):
        self.n, self.m = list(map(int, input().split(' ')))
        self.inp = list(map(int, input().split(' ')))

    def solve(self):
        self.inp.sort()

        need = sum(self.inp[i]+1 for i in range(self.n))

        need += self.inp[self.n-1]-self.inp[0]

        if need <= self.m:
            return "YES"

        return "NO"


t = int(input())

while t:

    t -= 1

    cur = Solver1668B()

    print(cur.solve())