class Solver1675C:

    def __init__(self):
        self.inp = input();
        self.n = len(self.inp)
        self.pref = [[[0] for _ in range(self.n)] for _ in range(3)]

    def eval(self, l, r):

        if l > r:
            return [0, 0, 0]

        if l == 0:
            return [self.pref[_][r] for _ in range(3)]

        return [self.pref[_][r]-self.pref[_][l-1] for _ in range(3)]

    def solve(self):

        sums = [0 for _ in range(3)]

        for i in range(self.n):
            if self.inp[i] == '0':
                sums[0] += 1
            elif self.inp[i] == '1':
                sums[1] += 1
            else:
                sums[2] += 1

            self.pref[0][i] = sums[0]
            self.pref[1][i] = sums[1]
            self.pref[2][i] = sums[2]

        outp = 0

        for i in range(self.n):
            prv = self.eval(0, i-1)
            nxt = self.eval(i+1, self.n-1)

            if prv[1]+prv[2] == i and nxt[0]+nxt[2] == self.n-i-1:
                outp += 1

        return outp

t = int(input())

while t:
    t -= 1

    cur=Solver1675C()

    print(cur.solve())