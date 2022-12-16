class Solver1700C:

    def __init__(self):
        self.n = int(input())
        self.inp = list(map(int, input().split(' ')))
        self.p = [0 for _ in range(self.n)]
        self.s = [0 for _ in range(self.n)]

    def solve(self):
        for i in range(self.n-1):
            if self.inp[i] - self.inp[i+1] > 0:
                self.p[i] = self.inp[i] - self.inp[i+1]
            else:
                self.s[i+1] = self.inp[i+1] - self.inp[i]

        sub = 0

        for i in range(self.n-1, -1, -1):
            sub += self.p[i]
            self.inp[i] -= sub

        sub = 0

        for i in range(self.n):
            sub += self.s[i]
            self.inp[i] -= sub

        #print(self.p, self.s, self.inp)

        return sum(self.p)+sum(self.s)+abs(self.inp[0])


t = int(input())

while t:

    t -= 1

    cur = Solver1700C()

    print(cur.solve())