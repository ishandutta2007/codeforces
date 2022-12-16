class Solver1692B:

    def __init__(self):
        self.n = int(input())
        self.inp = list(map(int, input().split(' ')))

    def solve(self):
        out = 0

        self.inp.sort()

        i = 0

        while i < self.n:
            j = i

            while j < self.n and self.inp[i] == self.inp[j]:
                j += 1

            j -= 1

            out += j-i

            i = j+1

        out = (out+1)//2*2

        return self.n-out


t = int(input())

while t:
    t -= 1

    cur = Solver1692B()

    print(cur.solve())