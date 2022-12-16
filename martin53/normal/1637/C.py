class Solver1637C:

    def __init__(self):
        self.n = int(input())
        self.inp = list(map(int, input().split(' ')))

    def solve(self):
        if self.n == 3 and self.inp[1] % 2 == 1:
            return -1

        wrong = 1

        for i in range(1, self.n-1):
            if self.inp[i] != 1:
                wrong = 0

        if wrong:
            return -1

        output = 0

        for i in range(1, self.n-1):
            output += (self.inp[i]+1)//2

        return output


t = int(input())

while t:

    t -= 1

    cur = Solver1637C()

    print(cur.solve())