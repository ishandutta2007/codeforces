class Solver1698C:

    def __init__(self):
        self.n = int(input())
        self.inp = list(map(int, input().split(' ')))

    def solve(self):

        if self.n <= 4:
            for i in range(self.n):
                for j in range(i+1, self.n):
                    for k in range(j+1, self.n):
                        ok = 0

                        for l in range(self.n):
                            if self.inp[i] + self.inp[j] + self.inp[k] == self.inp[l]:
                                ok = 1

                        if ok == 0:
                            return "NO"

            return "YES"

        self.inp.sort()

        for i in range(1, self.n-1):
            if self.inp[i] != 0:
                return "NO"

        if self.inp[0] == 0 or self.inp[self.n-1] == 0 or self.inp[0] + self.inp[self.n-1] == 0:
            return "YES"

        return "NO"


t = int(input())

while t:

    t -= 1

    cur = Solver1698C()

    print(cur.solve())