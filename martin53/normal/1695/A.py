class Solver1695A:

    def __init__(self):
        self.n, self.m = list(map(int, input().split(' ')))
        self.inp = []
        for i in range(self.n):
            self.inp.append(list(map(int, input().split(' '))))

    def solve(self):
        p = 0
        q = 0

        for i in range(self.n):
            for j in range(self.m):
                if self.inp[i][j] > self.inp[p][q]:
                    p = i
                    q = j

        return max(p+1, self.n-p)*max(q+1, self.m-q)


t = int(input())

while t:

    t -= 1

    cur = Solver1695A()

    print(cur.solve())