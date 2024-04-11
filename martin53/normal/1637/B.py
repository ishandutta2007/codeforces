class Solver1637B:

    def __init__(self):
        self.n = int(input())
        self.inp = list(map(int, input().split(' ')))
        self.dp = [[0 for i in range(self.n)] for j in range(self.n)]

    def solve(self):

        for i in range(self.n):
            seen = {}

            mex = 0

            for j in range(i, self.n):
                seen[self.inp[j]] = 1

                while mex in seen:
                    mex += 1

                self.dp[i][j] = mex+1

        output = 0

        for SZ in range(1, self.n+1):
            for i in range(self.n-SZ+1):
                j = i + SZ - 1

                for k in range(i, j):
                    self.dp[i][j] = max(self.dp[i][j], self.dp[i][k] + self.dp[k+1][j])

                output += self.dp[i][j]

                #print(i, j, output)

        return output


t = int(input())

while t:

    t -= 1

    cur = Solver1637B()

    print(cur.solve())