class Solver1635B:

    def __init__(self):
        self.n = int(input())
        self.inp = list(map(int, input().split(' ')))

    def solve(self):

        output = 0

        for i in range(1, self.n-1):
            if self.inp[i-1] < self.inp[i] and self.inp[i] > self.inp[i+1]:

                j = i

                if j+1 != self.n-1:
                    j += 1

                self.inp[j] = max(self.inp[j-1], self.inp[j+1])
                output += 1

        print(output)
        print(' '.join(map(str, self.inp)))


t = int(input())

while t:

    t -= 1

    cur = Solver1635B()

    cur.solve()