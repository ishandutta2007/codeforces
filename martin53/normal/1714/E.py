apply = lambda x: x if x%2 == 0 else x + x % 10

class Solver1714E:

    def __init__(self):
        self.n = int(input())
        self.inp = list(map(int, input().split(' ')))

    def solve(self):
        self.inp = list(map(apply, self.inp))

        self.inp = list(set(self.inp))

        if min(self.inp) == max(self.inp):
            return 1

        if len(list(filter(lambda x: x % 10 == 0, self.inp))):
            return 0

        types = [0] * 20
        types[2] = 1
        types[4] = 1
        types[8] = 1
        types[16] = 1

        SZ = len(list(filter(lambda x: types[x % 20] == 0, self.inp)))

        if SZ == 0 or SZ == len(self.inp):
            return 1

        return 0


t = int(input())

while t:

    t -= 1

    cur = Solver1714E()

    if cur.solve():
        print('Yes')
    else:
        print('No')