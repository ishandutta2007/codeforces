class Solver1629B:

    def __init__(self):
        self.l, self.r, self.k = list(map(int, input().split(' ')))

    def solve(self):

        if self.l == self.r:
            if self.l == 1:
                return 'NO'
            return 'YES'

        cnt_odd = (self.r-1) // 2 - self.l // 2 + 1

        if cnt_odd <= self.k:
            return 'YES'

        return 'NO'


t = int(input())

while t:

    t -= 1

    cur = Solver1629B()

    print(cur.solve())