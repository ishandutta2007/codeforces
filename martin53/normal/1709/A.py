class Solver1709A:

    def __init__(self):
        self.inp = [int(input())]
        self.inp = self.inp + list(map(int, input().split(' ')))

    def solve(self):
        return self.inp[self.inp[self.inp[0]]] != 0 and self.inp[self.inp[0]] != 0 and self.inp[0] != 0


t = int(input())

while t:

    t -= 1

    cur = Solver1709A()

    if cur.solve():
        print('YES')
    else:
        print('NO')