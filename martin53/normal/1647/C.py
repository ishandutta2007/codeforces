class Solver1647C:

    def __init__(self):
        self.n, self.m = list(map(int, input().split(' ')))
        self.st = []
        for i in range(self.n):
            self.st.append(input())

        self.inp = []
        for i in range(self.n):
            self.inp.append([])
            for j in range(self.m):
                if self.st[i][j] == '1':
                    self.inp[i].append(1)
                else:
                    self.inp[i].append(0)

    def solve(self):
        if self.inp[0][0] == 1:
            print("-1")
            return

        output = []

        for i in range(self.n):
            for j in range(self.m-1, 0, -1):
                if self.inp[i][j] == 1:
                    output.append([i, j-1, i, j])
                    self.inp[i][j] = 0

        for i in range(self.n-1, 0, -1):
            if self.inp[i][0] == 1:
                output.append([i-1, 0, i, 0])
                self.inp[i][0] = 0

        print(len(output))
        for i in range(len(output)):
            print(output[i][0]+1, output[i][1]+1, output[i][2]+1, output[i][3]+1)


t = int(input())

while t:

    t -= 1

    cur = Solver1647C()

    cur.solve()