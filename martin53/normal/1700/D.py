import sys

input = sys.stdin.readline


class Solver1700D:

    def __init__(self):
        self.n = int(input())
        self.inp = list(map(int, input().split(' ')))
        self.S = sum(self.inp)

        self.min_t = [0 for _ in range(self.n)]

        s_now = 0

        required = 0

        for i in range(self.n):
            s_now += self.inp[i]

            required = max(required, (s_now+i)//(i+1))

            self.min_t[i] = required

    def query(self):
        t = int(input())

        pos = (self.S + t - 1)//t

        if pos > self.n:
            return -1

        if t < self.min_t[pos-1]:
            return -1

        return pos

    def solve(self):
        q = int(input())

        while q:

            q -= 1

            print(self.query())


cur = Solver1700D()

cur.solve()