class Solver1708B:

    def __init__(self):
        self.n, self.l, self.r = list(map(int, input().split(' ')))

    def solve(self):
        output = []

        for i in range(1, self.n+1):
            current = self.r // i * i

            if current < self.l:
                print('NO')
                return

            output.append(current)

        print('YES')
        print(' '.join(map(str, output)))

t = int(input())

while t:

    t -= 1

    cur = Solver1708B()

    cur.solve()