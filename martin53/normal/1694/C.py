class Solver1694C:

    def __init__(self):
        self.n = int(input())
        self.inp = list(map(int, input().split(' ')))

    def solve(self):
        for i in range(self.n-1):

            if self.inp[i] < 0:
                return "No"

            if self.inp[i] == 0:
                break

            self.inp[i+1] += self.inp[i]
            self.inp[i] = 0

        for i in range(self.n):
            if self.inp[i] != 0:
                return "No"

        return "Yes"


t = int(input())

while t:

    t -= 1

    cur = Solver1694C()

    print(cur.solve())