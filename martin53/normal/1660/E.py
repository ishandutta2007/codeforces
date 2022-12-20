import sys

input = sys.stdin.readline


class Solver1660E:

    def __init__(self):
        self.n = input()
        self.n = int(input())
        self.inp = []

        for i in range(self.n):
            self.inp.append(input())

    def solve(self):
        cnt = [0 for _ in range(self.n)]

        ones = 0
        for i in range(self.n):
            for j in range(self.n):
                if self.inp[i][j] == '1':
                    ones += 1
                    cnt[(i - j + self.n) % self.n] += 1

        fixed = max(cnt)

        return ones - fixed + self.n - fixed


t = int(input())

while t:

    t -= 1

    cur = Solver1660E()

    print(cur.solve())