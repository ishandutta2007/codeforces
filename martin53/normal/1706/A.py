class Solver1706A:

    def __init__(self):
        self.n, self.m = list(map(int, input().split(' ')))
        self.inp = list(map(int, input().split(' ')))

    def solve(self):
        seen = [0] * (self.m+2)

        for j in self.inp:
            if seen[min(j, self.m+1-j)] == 0:
                seen[min(j, self.m + 1 - j)] = 1
            else:
                seen[max(j, self.m + 1 - j)] = 1

        for i in range(1, self.m+1):
            if seen[i]:
                print('A', end='')
            else:
                print('B', end='')

        print()


t = int(input())

while t:

    t -= 1

    cur = Solver1706A()

    cur.solve()