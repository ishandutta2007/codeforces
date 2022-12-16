calc = lambda x, y: x-y if x>y else 0

class Solver1709B:

    def __init__(self):
        self.n, self.q = list(map(int, input().split(' ')))
        self.inp = list(map(int, input().split(' ')))

    def solve(self):

        pref = [0] + [max(0, self.inp[i-1] - self.inp[i]) for i in range(1, self.n)]

        suff = [0] + [max(0, self.inp[i] - self.inp[i-1]) for i in range(1, self.n)]

        for i in range(1, self.n):
            pref[i] += pref[i-1]
            suff[i] += suff[i-1]

        for i in range(self.q):
            l, r = list(map(int, input().split(' ')))

            if l <= r:
                print(pref[r-1] - pref[l-1])
            else:
                print(suff[l-1] - suff[r-1])



t = 1

while t:

    t -= 1

    cur = Solver1709B()

    cur.solve()