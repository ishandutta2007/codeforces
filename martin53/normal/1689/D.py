import sys

input = sys.stdin.readline


class Solver1689D:

    def __init__(self):
        self.n, self.m = list(map(int, input().split(' ')))
        self.inp = []

        for i in range(self.n):
            self.inp.append(input())

        self.up_left = [[-self.n - self.m for _ in range(self.m)] for _ in range(self.n)]
        self.up_right = [[-self.n - self.m for _ in range(self.m)] for _ in range(self.n)]
        self.down_left = [[-self.n - self.m for _ in range(self.m)] for _ in range(self.n)]
        self.down_right = [[-self.n - self.m for _ in range(self.m)] for _ in range(self.n)]

    def solve(self):
        for p in range(self.n):
            for q in range(self.m):
                if self.inp[p][q] == 'B':
                    self.up_left[p][q] = - p - q
                    self.up_right[p][q] = - p + q
                    self.down_left[p][q] = + p - q
                    self.down_right[p][q] = + p + q

        for p in range(self.n):
            for q in range(self.m):
                if p > 0:
                    self.up_left[p][q] = max(self.up_left[p][q], self.up_left[p - 1][q])
                if q > 0:
                    self.up_left[p][q] = max(self.up_left[p][q], self.up_left[p][q - 1])

        for p in range(self.n):
            for q in range(self.m-1, -1, -1):
                if p > 0:
                    self.up_right[p][q] = max(self.up_right[p][q], self.up_right[p - 1][q])
                if q < self.m - 1:
                    self.up_right[p][q] = max(self.up_right[p][q], self.up_right[p][q + 1])

        for p in range(self.n-1, -1, -1):
            for q in range(self.m-1, -1, -1):
                if p < self.n - 1:
                    self.down_right[p][q] = max(self.down_right[p][q], self.down_right[p + 1][q])
                if q < self.m - 1:
                    self.down_right[p][q] = max(self.down_right[p][q], self.down_right[p][q + 1])

        for p in range(self.n-1, -1, -1):
            for q in range(self.m):
                if p < self.n - 1:
                    self.down_left[p][q] = max(self.down_left[p][q], self.down_left[p + 1][q])
                if q > 0:
                    self.down_left[p][q] = max(self.down_left[p][q], self.down_left[p][q - 1])

        x = 0
        y = 0
        score = self.n+self.m

        for i in range(self.n):
            for j in range(self.m):
                cur_score = i + j + self.up_left[i][j]
                cur_score = max(cur_score, i - j + self.up_right[i][j])
                cur_score = max(cur_score, - i - j + self.down_right[i][j])
                cur_score = max(cur_score, - i + j + self.down_left[i][j])

                #print(i,j,cur_score)

                if cur_score < score:
                    score = cur_score
                    x = i
                    y = j

        #print(self.up_left,self.up_right,self.down_left,self.down_right)

        print(x+1, y+1)


t = int(input())

while t:
    t -= 1

    cur = Solver1689D()

    cur.solve()