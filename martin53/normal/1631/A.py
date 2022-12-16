class Solver1631A:

    def __init__(self):
        self.n = int(input())
        self.a = list(map(int, input().split(' ')))
        self.b = list(map(int, input().split(' ')))

    def solve(self):
        for i in range(self.n):
            if self.a[i] < self.b[i]:
                temp = self.a[i]
                self.a[i] = self.b[i]
                self.b[i] = temp

        return max(self.a) * max(self.b)

t = int(input())

while t:

    t -= 1

    cur = Solver1631A()

    print(cur.solve())