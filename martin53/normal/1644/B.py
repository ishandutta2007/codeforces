class Solver1644B:

    def __init__(self):
        self.n = int(input())

    def solve(self):
        if self.n == 3:
            print("3 2 1")
            print("2 3 1")
            print("1 3 2")
            return

        for i in range(1, self.n+1):
            for j in range(i, 0, -1):
                print(j, end=' ')

            for j in range(self.n, i, -1):
                print(j, end=' ')

            print()


t = int(input())

while t:

    t -= 1

    cur = Solver1644B()

    cur.solve()