minutes = lambda x, y: 60*x+y

time_spent = lambda x, y: y-x if x<=y else 1440+y-x

class Solver1714A:

    def __init__(self):
        self.n, x, y = list(map(int, input().split(' ')))

        self.t = minutes(x, y)

        self.inp = []

        for i in range(self.n):
            x, y = list(map(int, input().split(' ')))

            self.inp.append(minutes(x, y))

    def solve(self):
        #print(self.n, self.t, self.inp)
        out = min(time_spent(self.t, self.inp[_]) for _ in range(self.n))
        print(out//60, out % 60)


t = int(input())

while t:

    t -= 1

    cur = Solver1714A()

    cur.solve()