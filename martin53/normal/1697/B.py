import sys

input = sys.stdin.readline


class Solver1697B:

    def __init__(self):
        self.n, self.q = list(map(int, input().split(' ')))
        self.inp = list(map(int, input().split(' ')))

        self.inp.sort()

        self.pref = []

        sum = 0

        for i in range(self.n):
            sum += self.inp[i]
            self.pref.append(sum)

    def solve(self):
        x, y = list(map(int, input().split(' ')))

        ret = self.pref[self.n - 1 - x + y]
        if self.n - 1 - x >= 0:
            ret -= self.pref[self.n - 1 - x]

        return ret


cur = Solver1697B()

while cur.q:

    cur.q -= 1

    print(cur.solve())