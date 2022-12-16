class solver1676G:

    def __init__(self):
        self.n = int(input())
        self.parents = list(map(int, input().split(' ')))
        self.inp = input()
        self.diff = []

    def solve(self):
        for i in range(0, self.n):
            if self.inp[i] == 'B':
                self.diff.append(-1)
            else:
                self.diff.append(1)

        for i in range(self.n-2, -1, -1):
            self.diff[self.parents[i]-1] += self.diff[i+1]

        #print(self.diff)

        outp = 0

        for i in range(self.n):
            if self.diff[i] == 0:
                outp += 1

        return outp


t = int(input())

while t:
    t -= 1

    cur = solver1676G()

    print(cur.solve())