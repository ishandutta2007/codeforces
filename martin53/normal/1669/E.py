class Solver1669E:

    def __init__(self):
        self.alpha = 26

        self.n = int(input())

        self.inp = []

        for i in range(self.n):
            self.inp.append(input())

    def solve(self):
        cnt = [[0 for _ in range(self.alpha)] for _ in range(self.alpha)]

        output = 0

        for i in range(self.n):
            p = ord(self.inp[i][0])-ord('a')
            q = ord(self.inp[i][1])-ord('a')

            output -= 2*cnt[p][q]

            for j in range(self.alpha):
                output += cnt[p][j] + cnt[j][q]

            cnt[p][q] += 1

        return output


t = int(input())

while t:
    t -= 1

    cur = Solver1669E()

    print(cur.solve())