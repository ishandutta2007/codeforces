import sys

input = sys.stdin.readline

class Solver1670C:

    def __init__(self):
        self.n = int(input())
        self.a = list(map(int, input().split(' ')))
        self.b = list(map(int, input().split(' ')))
        self.d = list(map(int, input().split(' ')))

        self.pos_a = [0 for _ in range(self.n+1)]
        self.pos_b = [0 for _ in range(self.n+1)]

        self.been = [0 for _ in range(self.n+1)]

        self.mod = (10**9)+7

    def solve(self):

        for i in range(0, self.n):
            self.pos_a[self.a[i]] = i
            self.pos_b[self.b[i]] = i

        for i in range(0, self.n):
            if self.d[i] and self.been[i] == 0:

                if self.d[i] == self.a[i]:
                    j = i
                    while self.been[j] == 0:
                        self.been[j] = 1
                        j = self.pos_a[self.b[j]]

                else:
                    j = i
                    while self.been[j] == 0:
                        self.been[j] = 1
                        j = self.pos_b[self.a[j]]

        outp = 1

        for i in range(0, self.n):
            if self.been[i] == 0:
                cnt = 0
                j = i
                while self.been[j] == 0:
                    self.been[j] = 1
                    j = self.pos_a[self.b[j]]

                    cnt += 1

                if cnt >= 2:
                    outp = outp * 2 % self.mod

        return outp


t = int(input())

while t:

    t -= 1

    cur = Solver1670C()

    print(cur.solve())