import sys

input = sys.stdin.readline


class Solver1657C:

    def __init__(self):
        self.n = int(input())
        self.inp = input()

    def solve(self):
        operations = 0

        i = 0

        while i < self.n - 1:
            if self.inp[i] == '(':
                i += 2
                operations += 1
            else:
                j = i+1

                while j < self.n and self.inp[j] != ')':
                    j += 1

                if j == self.n:
                    break

                i = j+1
                operations += 1

        print(operations, self.n-i)


t = int(input())

while t:

    t -= 1

    cur = Solver1657C()

    cur.solve()