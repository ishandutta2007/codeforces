class Solver1674D:

    def __init__(self):
        self.n = int(input())
        self.inp = list(map(int, input().split(' ')))

    def solve(self):
        for i in range(self.n-1, 0, -2):
            if self.inp[i-1] > self.inp[i]:
                temp = self.inp[i-1]
                self.inp[i-1] = self.inp[i]
                self.inp[i] = temp

        for i in range(1, self.n):
            if self.inp[i-1] > self.inp[i]:
                return "NO"

        return "YES"


t = int(input())

while t:
    t -= 1

    cur = Solver1674D()

    print(cur.solve())