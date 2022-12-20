class Solver1696E:

    def __init__(self):
        self.mod = (10**9)+7

        self.n = int(input())

        self.inp = list(map(int, input().split(' ')))

        self.factorial = []

        self.inverse = []

        self.inverse_factorial = []

        self.nmax = 4 * (10**5) + 42

    def comb(self, p, q):

        if p < 0 or q < 0 or p - q < 0:
            return 0

        return self.factorial[p] * self.inverse_factorial[q] % self.mod * self.inverse_factorial[p-q] % self.mod

    def solve(self):
        self.factorial.append(1)

        for i in range(1, self.nmax):
            self.factorial.append(self.factorial[i-1] * i % self.mod)

        self.inverse.append(1)
        self.inverse.append(1)

        for i in range(2, self.nmax):
            self.inverse.append((self.mod - self.mod//i) * self.inverse[self.mod % i] % self.mod)

        self.inverse_factorial.append(1)

        for i in range(1, self.nmax):
            self.inverse_factorial.append(self.inverse_factorial[i-1] * self.inverse[i] % self.mod)

        output = 0

        for i in range(self.n+1):
            if self.inp[i] != 0:
                output = (output + self.comb(i+self.inp[i], i+1) + self.mod) % self.mod

        return output


cur = Solver1696E()

print(cur.solve())