class Solver1635C:

    def __init__(self):
        self.n = int(input())
        self.inp = list(map(int, input().split(' ')))

    def solve(self):

        if self.inp[self.n-2] > self.inp[self.n-1]:
            print(-1)
            return

        if self.inp[self.n-1] < 0:
            for i in range(1, self.n):
                if self.inp[i-1] > self.inp[i]:
                    print(-1)
                    return

            print(0)
            return

        print(self.n-2)
        for i in range(self.n-3, -1, -1):
            print(i+1, self.n-1, self.n)


t = int(input())

while t:

    t -= 1

    cur = Solver1635C()

    cur.solve()