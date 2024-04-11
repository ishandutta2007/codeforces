class Solver1669C:

    def __init__(self):
        self.n = int(input())
        self.inp = list(map(int, input().split(' ')))

    def solve(self):
        for i in range(2, self.n):
            if self.inp[i] % 2 != self.inp[i-2] % 2:
                return "NO"

        return "YES"


t = int(input())

while t:
    t -= 1

    cur = Solver1669C()

    print(cur.solve())