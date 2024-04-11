import sys

input = sys.stdin.readline


class solver_1679E:

    def __init__(self):
        self.n = int(input())
        self.str = input()
        self.inp = []

        for i in range(self.n):
            if 'a' <= self.str[i] and self.str[i] <= 'q':
                self.inp.append(ord(self.str[i])-ord('a'))
            else:
                self.inp.append(17)

        self.pref = []

        cnt = 0

        for i in range(self.n):
            if self.inp[i] == 17:
                cnt = cnt+1

            self.pref.append(cnt)

        self.mod = 998244353

        self.free = [[0 for _ in range(self.n)] for _ in range(self.n)]
        self.required = [[0 for _ in range(self.n)] for _ in range(self.n)]

        for i in range(self.n):
            if self.inp[i] == 17:
                self.free[i][i] = 1

        for SZ in range(2, self.n+1):
            for l in range(0, self.n+1-SZ):
                r = l+SZ-1

                if self.inp[l] == 17 and self.inp[r] == 17:
                    self.required[l][r] = self.required[l+1][r-1]
                    self.free[l][r] = self.free[l+1][r-1]+1

                elif self.inp[l] == 17 and self.inp[r] != 17:
                    self.required[l][r] = (self.required[l+1][r-1] | (1 << self.inp[r]))
                    self.free[l][r] = self.free[l+1][r-1]

                elif self.inp[l] != 17 and self.inp[r] == 17:
                    self.required[l][r] = (self.required[l+1][r-1] | (1 << self.inp[l]))
                    self.free[l][r] = self.free[l+1][r-1]

                elif self.inp[l] != self.inp[r]:
                    self.required[l][r] = (self.required[l + 1][r - 1] | (1 << 17))
                    self.free[l][r] = self.free[l + 1][r - 1]

                else:
                    self.required[l][r] = self.required[l + 1][r - 1]
                    self.free[l][r] = self.free[l + 1][r - 1]

        self.pwr = []

        for i in range(0, 18):
            cur = 1

            self.pwr.append([])
            self.pwr[i].append(cur)

            for j in range(1, self.n+1):
                cur = cur*i % self.mod
                self.pwr[i].append(cur)

        self.mem = []

        for len in range(0, 18):

            cur = [0 for _ in range(1 << 17)]

            for i in range(0, self.n):
                for j in range(i, self.n):
                    if self.required[i][j] < (1 << 17):

                        pwr = self.free[i][j]
                        if i:
                            pwr += self.pref[i-1]

                        pwr += self.pref[self.n-1]-self.pref[j]

                        cur[self.required[i][j]] = (cur[self.required[i][j]]+self.pwr[len][pwr]) % self.mod

            for i in range(0, 17):
                for mask in range(0, 1 << 17):
                    if (mask & (1 << i)):
                        cur[mask] = (cur[mask]+cur[mask-(1 << i)])

            self.mem.append(cur)

    def query(self):

        cur = input()

        mask = 0

        for j in range(len(cur)-1):
            now = ord(cur[j])-ord('a')

            mask += (1 << now)

        return self.mem[len(cur)-1][mask] % self.mod


cur = solver_1679E()

q = int(input())

while q:
    q = q-1

    print(cur.query())