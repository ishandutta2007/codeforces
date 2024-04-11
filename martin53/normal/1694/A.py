class Solver1694A:

    def __init__(self):
        self.a, self.b = list(map(int, input().split(' ')))

    def solve(self):
        if self.a <= self.b:
            for i in range(self.b - self.a):
                print('1', end='')
            for i in range(self.a):
                print('01', end='')
        else:
            for i in range(self.a - self.b):
                print('0', end='')
            for i in range(self.b):
                print('10', end='')
        print()


t = int(input())

while t:

    t -= 1

    cur = Solver1694A()

    cur.solve()