import sys

input = sys.stdin.readline

class solver1678D:

    def __init__(self):
        self.n, self.m = list(map(int, input().split(' ')))
        self.inp = input()

        self.col = [0 for _ in range(self.n*self.m)]
        self.row = [0 for _ in range(self.n*self.m)]

    def solve(self):

        seen = [0 for _ in range(self.m)]

        for i in range(0, self.n*self.m):
            if seen[i % self.m] == 0 and self.inp[i] == '1':
                seen[i % self.m] = 1
                self.col[i] = 1

        pref = []

        pref_sum = 0

        for i in range(self.n*self.m):
            if self.inp[i] == '1':
                pref_sum += 1
            pref.append(pref_sum)

        for i in range(self.n*self.m):
            cur_sum = pref[i]

            if i >= self.m:
                cur_sum -= pref[i-self.m]

            if cur_sum:
                self.row[i] = 1

        for i in range(self.m, self.n*self.m):
            self.row[i] += self.row[i-self.m]

        for i in range(1, self.n*self.m):
            self.col[i] += self.col[i-1]

        outp=[]

        for i in range(0, self.n*self.m):
            outp.append(self.row[i]+self.col[i])

        sys.stdout.write(" ".join(map(str, outp)) + "\n")


t = int(input())

while t:
    t -= 1

    cur = solver1678D()

    cur.solve()