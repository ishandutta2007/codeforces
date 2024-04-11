class Solver1631B:

    def __init__(self):
        self.n = int(input())
        self.inp = list(map(int, input().split(' ')))

    def solve(self):

        output = 0

        while max(self.inp) != min(self.inp):
            output += 1

            i = self.n - 1

            while self.inp[i] == self.inp[self.n-1]:
                i -= 1

            i += 1

            for v in range(max(0, 2*i - self.n), self.n):
                self.inp[v] = self.inp[self.n-1]

        return output


t = int(input())

while t:

    t -= 1

    cur = Solver1631B()

    print(cur.solve())