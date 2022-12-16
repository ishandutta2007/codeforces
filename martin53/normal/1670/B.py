import sys

input = sys.stdin.readline

class Solver1670B:

    def __init__(self):
        self.n = int(input())
        self.inp = input()
        self.special = list(map(str, input().split(' ')))
        self.seen = [0 for _ in range(0, 26)]

    def solve(self):

        for i in range(1, len(self.special)):
            self.seen[ord(self.special[i][0])-ord('a')] = 1

        outp = 0

        cnt = 0

        for i in range(self.n):

            if self.seen[ord(self.inp[i])-ord('a')]:
                outp = max(outp, cnt)
                cnt = 1
            else:
                cnt += 1

        return outp


t = int(input())

while t:
    t -= 1

    cur = Solver1670B()

    print(cur.solve())