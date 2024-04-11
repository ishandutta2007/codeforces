class Solver1673C:

    def __init__(self):
        self.MX = 4*(10**4)+42
        self.mod = (10**9)+7
        self.dp = [0 for _ in range(self.MX)]
        self.dp[0] = 1

        for i in range(1, self.MX):
            cur = str(i)

            cur2 = cur[::-1]

            if cur == cur2:
                for j in range(i, self.MX):
                    self.dp[j] = (self.dp[j]+self.dp[j-i]) % self.mod

    def solve(self):
        n = int(input())
        return self.dp[n]


t = int(input())

cur = Solver1673C()

while t:

    t -= 1

    print(cur.solve())