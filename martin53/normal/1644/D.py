class Solver1644D:

    def __init__(self):
        self.mod = 998244353
        self.n, self.m, self.k, self.q = list(map(int, input().split(' ')))
        self.inp = []

        for i in range(self.q):
            x, y = list(map(int, input().split(' ')))
            self.inp.append([x, y])

    def solve(self):
        seen_x = {}
        seen_y = {}

        output = 1

        for i in range(self.q-1, -1, -1):

            #print(seen_x.get(self.inp[i][0]), seen_y.get(self.inp[i][1]))

            if len(seen_x) != self.n and len(seen_y) != self.m and (seen_x.get(self.inp[i][0]) == None or seen_y.get(self.inp[i][1]) == None):
                output = output*self.k % self.mod
                seen_x[self.inp[i][0]] = 1
                seen_y[self.inp[i][1]] = 1

        return output


t = int(input())

while t:

    t -= 1

    cur = Solver1644D()

    print(cur.solve())