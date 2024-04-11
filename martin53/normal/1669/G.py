class Solver1669G:

    def __init__(self):
        self.n, self.m = list(map(int, input().split(' ')))
        self.inp = []

        for i in range(self.n):
            self.inp.append(input())

    def solve(self):
        input_copy = [['-' for j in range(self.m)] for i in range(self.n)]

        for i in range(self.n):
            for j in range(self.m):
                input_copy[i][j] = self.inp[i][j]

        go = 1

        while go:
            go = 0

            for j in range(self.m):
                for i in range(self.n-2, -1, -1):
                    if input_copy[i][j] == '*' and input_copy[i+1][j] == '.':
                        temp = input_copy[i][j]
                        input_copy[i][j] = input_copy[i+1][j]
                        input_copy[i+1][j] = temp

                        go = 1

        for i in range(self.n):
            for j in range(self.m):
                print(input_copy[i][j], end='')
            print()


t = int(input())

while t:

    t -= 1

    cur = Solver1669G()

    cur.solve()