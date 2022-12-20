class Solver1665D:

    def __init__(self):
        self.a = 0
        self.C = 30

    def solve(self):
        for i in range(1, self.C+1):
            print("?", self.a+1, self.a + (1 << i) + 1)
            res = int(input())
            if res != (1 << i):
                self.a += (1 << (i-1))

        return (1 << self.C) - self.a - 1


t = int(input())

while t:

    t -= 1

    cur = Solver1665D()

    print("!", cur.solve())