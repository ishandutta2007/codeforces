class Solver1647B:

    def __init__(self):
        self.n, self.m = list(map(int, input().split(' ')))
        self.inp = []
        for i in range(self.n):
            self.inp.append(input())

    def solve(self):
        for i in range(1, self.n):
            for j in range(1, self.m):
                ones = 0

                if self.inp[i][j] == '1':
                    ones += 1

                if self.inp[i-1][j] == '1':
                    ones += 1

                if self.inp[i][j-1] == '1':
                    ones += 1

                if self.inp[i-1][j-1] == '1':
                    ones += 1

                if ones == 3:
                    return "NO"

        return "YES"


t = int(input())

while t:

    t -= 1

    cur = Solver1647B()

    print(cur.solve())