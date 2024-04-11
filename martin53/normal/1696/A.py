class Solver1696A:

    def __init__(self):
        self.n, self.z = list(map(int, input().split(' ')))
        self.inp = list(map(int, input().split(' ')))

    def solve(self):
        return max(self.inp[i] | self.z for i in range(self.n))


t = int(input())

while t:

    t -= 1

    cur = Solver1696A()

    print(cur.solve())