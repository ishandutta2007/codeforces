class Solver1703C:

    def __init__(self):
        self.n = int(input())

        self.inp = list(map(int, input().split(' ')))

        for i in range(self.n):
            cur = list(map(str, input().split(' ')))

            for j in cur[1]:
                if j == 'D':
                    self.inp[i] = (self.inp[i] + 1) % 10
                else:
                    self.inp[i] = (self.inp[i] + 9) % 10

    def solve(self):
        return self.inp


t = int(input())

while t:

    t -= 1

    cur = Solver1703C()

    print(' '.join(map(str, cur.solve())))