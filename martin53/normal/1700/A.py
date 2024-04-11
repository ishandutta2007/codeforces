class Solver1700A:

    def __init__(self):
        self.n, self.m = list(map(int, input().split(' ')))

    def solve(self):

        return (self.m-1)*self.m//2 + self.m*(self.n+1)*self.n//2

t = int(input())

while t:

    t -= 1

    cur = Solver1700A()

    print(cur.solve())