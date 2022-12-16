class Solver1703E:

    def __init__(self):
        self.n = int(input())
        self.inp = []

        for j in range(self.n):
            cur = input()

            self.inp.append([])

            for p in cur:
                if p == '1':
                    self.inp[j].append(1)
                else:
                    self.inp[j].append(0)

    def solve(self):
        output = 0

        for i in range(self.n//2):
            for j in range((self.n+1)//2):

                cnt = [0, 0]

                cnt[self.inp[i][j]] += 1
                cnt[self.inp[j][self.n-1-i]] += 1
                cnt[self.inp[self.n-1-i][self.n-1-j]] += 1
                cnt[self.inp[self.n-1-j][i]] += 1

                output += min(cnt)

        return output


t = int(input())

while t:

    t -= 1

    cur = Solver1703E()

    print(cur.solve())