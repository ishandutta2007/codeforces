class Solver1689B:

    def __init__(self):
        self.n = int(input())
        self.inp = list(map(int, input().split(' ')))
        self.outp = [i + 1 for i in range(self.n)]

    def swap(self, i, j):
        temp = self.outp[i]
        self.outp[i] = self.outp[j]
        self.outp[j] = temp

    def solve(self):

        if self.n == 1:
            print(-1)
            return

        for i in range(self.n-1):
            if self.outp[i] == self.inp[i]:
                self.swap(i, i+1)

        if self.inp[self.n-1] == self.outp[self.n-1]:
            self.swap(self.n-2, self.n-1)

        print(' '.join(map(str, self.outp)))


t = int(input())

while t:
    t -= 1

    cur = Solver1689B()

    cur.solve()