class Solver1668A:

    def __init__(self):
        self.n, self.m = list(map(int, input().split(' ')))

    def solve(self):
        if self.n > self.m:
            temp = self.n
            self.n = self.m
            self.m = temp

        if self.n == 1:
            if self.m >= 3:
                return -1
            else:
                return self.m - 1
        elif self.n % 2 == self.m % 2:
            return 2*(self.m-1)
        return 2*self.m - 3


t = int(input())

while t:
    t -= 1

    cur = Solver1668A()

    print(cur.solve())