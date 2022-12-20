class Solver1696B:

    def __init__(self):
        self.n = int(input())
        self.inp = list(map(int, input().split(' ')))

    def solve(self):
        output = 0

        i = 0

        while i < self.n:
            if self.inp[i] == 0:
                i += 1
                continue

            j = i

            while j < self.n and self.inp[j] != 0:
                j += 1

            output += 1

            i = j

        return min(2, output)


t = int(input())

while t:

    t -= 1

    cur = Solver1696B()

    print(cur.solve())