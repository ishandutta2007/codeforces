class Solver1692H:

    def __init__(self):
        self.n = int(input())
        self.inp = list(map(int, input().split(' ')))

    def solve(self):
        values = []

        for i in range(self.n):
            values.append([self.inp[i], i])

        values.sort()

        a = self.inp[0]
        l = 0
        r = 0
        score = 1

        i = 0

        #print(values)

        while i < self.n:
            j = i

            while j < self.n and values[i][0] == values[j][0]:
                j += 1

            i_best = i

            for j_best in range(i+1, j):

                if values[i_best][1] - 2*i_best < values[j_best][1] - 2*j_best:
                    i_best = j_best

                if 2*j_best - values[j_best][1] + values[i_best][1] - 2*i_best + 1 > score:
                    l = values[i_best][1]
                    r = values[j_best][1]
                    a = values[i_best][0]

                    score = 2*j_best - values[j_best][1] + values[i_best][1] - 2*i_best + 1

                #print(i, j, j_best, i_best, score, l, r)

            j -= 1

            i = j + 1

        print(a, l+1, r+1)


t = int(input())

while t:

    t -= 1

    cur = Solver1692H()

    cur.solve()