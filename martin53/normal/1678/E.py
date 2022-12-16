class solver1678E:

    def __init__(self):
        self.n = int(input())
        self.a = list(map(int, input().split(' ')))
        self.b = list(map(int, input().split(' ')))

        self.hsh = [0 for _ in range(self.n+1)]
        self.been = [0 for _ in range(self.n)]

    def solve(self):
        for i in range(self.n):
            self.hsh[self.a[i]] = i

        for i in range(self.n):
            self.b[i] = self.hsh[self.b[i]]

        take = 0

        for i in range(self.n):
            if self.been[i] == 0:
                cnt = 0
                j = i

                while self.been[j] == 0:
                    cnt += 1
                    self.been[j] = 1
                    j = self.b[j]

                take += cnt//2

        return 2*take*(self.n-take)


t = int(input())

while t:
    t = t-1

    cur = solver1678E()

    print(cur.solve())