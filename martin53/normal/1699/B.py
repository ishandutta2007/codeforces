def check(i):
    return 1 <= i % 4 and i % 4 <= 2


class Solver1699B:
    def __init__(self):
        self.n, self.m = list(map(int, input().split(' ')))

    def solve(self):
        for i in range(self.n):
            for j in range(self.m):
                if check(i) == check(j):
                    print(1, end=' ')
                else:
                    print(0, end=' ')
            print()


t = int(input())

while t:

    t -= 1

    cur = Solver1699B()

    cur.solve()