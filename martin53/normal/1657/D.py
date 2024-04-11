import sys

input = sys.stdin.readline


class Solver1657D:

    def __init__(self):
        self.n, self.C = list(map(int, input().split(' ')))
        self.inp = []
        self.power = [0 for _ in range(self.C+1)]

        for i in range(self.n):
            c, d, h = list(map(int, input().split(' ')))
            self.power[c] = max(self.power[c], d*h)

    def prepare(self):
        for i in range(1, self.C+1):
            for j in range(i, self.C+1, i):
                self.power[j] = max(self.power[j], j//i*self.power[i])

        for i in range(1, self.C+1):
            self.power[i] = max(self.power[i-1], self.power[i])

        #print(self.power)

    def query(self):

        d, h = list(map(int, input().split(' ')))

        product = d*h + 1

        if self.power[self.C] < product:
            return -1

        ok = self.C
        not_ok = 0

        while ok - not_ok > 1:
            av = (ok+not_ok)//2

            if self.power[av] >= product:
                ok = av
            else:
                not_ok = av

        return ok

    def solve(self):

        self.prepare()

        q = int(input())

        while q:

            q -= 1

            print(self.query(), end=' ')

        print()


cur = Solver1657D()

cur.solve()