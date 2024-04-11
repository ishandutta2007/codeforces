class Solver1692A:

    def __init__(self):
        self.inp = list(map(int, input().split(' ')))

    def solve(self):
        cnt = 0
        for i in range(1, len(self.inp)):
            if self.inp[i] > self.inp[0]:
                cnt += 1

        return cnt


t = int(input())

while t:

    t -= 1

    cur = Solver1692A()

    print(cur.solve())