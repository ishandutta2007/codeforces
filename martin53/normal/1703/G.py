class Solver1703G:

    def __init__(self):
        self.n, self.k = list(map(int, input().split(' ')))
        self.inp = list(map(int, input().split(' ')))

    def solve(self):
        output = sum(self.inp) - self.n*self.k

        taken_good = 0

        for i in range(self.n):
            cur = taken_good

            for j in range(i, min(i+30, self.n)):
                cur += self.inp[j] // (1<<(j+1-i))

            output = max(output, cur)

            taken_good += self.inp[i] - self.k

        return output


t = int(input())

while t:

    t -= 1

    cur = Solver1703G()

    print(cur.solve())