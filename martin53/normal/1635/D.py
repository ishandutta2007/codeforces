class Solver1635D:

    def __init__(self):
        self.mod = (10**9)+7
        self.n, self.p = list(map(int, input().split(' ')))
        self.inp = list(map(int, input().split(' ')))
        self.dp = [0 for _ in range(self.p+1)]
        self.seen = {}

    def solve(self):
        self.inp.sort()

        for i in range(self.n):
            go_on = 1

            cur = self.inp[i]

            while cur > 0:
                if cur in self.seen:
                    go_on = 0
                    break

                if cur % 2 == 1:
                    cur = (cur - 1) // 2
                elif cur % 4 == 0:
                    cur = cur // 4
                else:
                    break

            if go_on == 0:
                continue

            self.seen[self.inp[i]] = 1

            steps = 0

            while self.inp[i]:
                steps += 1
                self.inp[i] = self.inp[i] // 2

            if steps <= self.p:
                self.dp[steps] += 1

        #(self.dp)

        for i in range(self.p+1):
            if i >= 1:
                self.dp[i] = (self.dp[i] + self.dp[i-1]) % self.mod
            if i >= 2:
                self.dp[i] = (self.dp[i] + self.dp[i - 2]) % self.mod

        #print(self.dp)

        return sum(self.dp) % self.mod


cur = Solver1635D()

print(cur.solve())