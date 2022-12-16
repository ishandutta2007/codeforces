class Solver1692D:

    def __init__(self):
        self.raw = list(map(str, input().split(' ')))
        self.inp = self.raw[0].split(':')
        self.h = int(self.inp[0])
        self.m = int(self.inp[1])
        self.t = int(self.raw[1])

    def solve(self):
        #print(self.h, self.m, self.t)
        output = 0

        for t in range(1, 1441):
            self.h += self.t//60
            self.m += self.t % 60

            self.h += self.m//60
            self.m = self.m % 60

            self.h = self.h % 24

            if self.h//10 == self.m % 10 and self.h % 10 == self.m//10:
                output += 1

            if (t*self.t) % 1440 == 0:
                break

        return output


t = int(input())

while t:
    t -= 1

    cur = Solver1692D()

    print(cur.solve())