import sys

input = sys.stdin.readline


class Solver1675E:

    def __init__(self):
        self.n, self.k = list(map(int, input().split(' ')))
        self.inp = input()

    def solve(self):

        outp = []

        for i in range(self.n):
            if ord(self.inp[i])-ord('a') > self.k:

                MX = 'a'

                for j in range(i):
                    MX = max(self.inp[j], MX)

                self.k -= (ord(MX)-ord('a'))

                for j in range(self.n):
                    if self.inp[j] <= MX:
                        outp += str('a')
                    elif self.inp[j] <= self.inp[i]:

                        cur = min(ord(self.inp[j]), ord(self.inp[i]) - self.k)

                        outp.append(chr(cur))
                    else:
                        outp.append(self.inp[j])

                return outp

        for i in range(self.n):
            outp.append('a')

        return outp


t = int(input())

while t:
    t -= 1

    cur = Solver1675E()

    print(''.join(cur.solve()))