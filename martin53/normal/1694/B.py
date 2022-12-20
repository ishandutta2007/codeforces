class Solver1694B:

    def __init__(self):
        self.n = int(input())
        self.inp = input()

    def solve(self):
        output = 1

        for i in range(1, self.n):
            if self.inp[i-1] == self.inp[i]:
                output += 1
            else:
                output += i+1

        return output


t = int(input())

while t:

    t -= 1

    cur = Solver1694B()

    print(cur.solve())