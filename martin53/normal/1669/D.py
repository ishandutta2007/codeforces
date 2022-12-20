class Solver1669D:

    def __init__(self):
        self.n = int(input())
        self.inp = input()

    def solve(self):
        i = 0

        while i < self.n:
            if self.inp[i] == 'W':
                i += 1
                continue

            j = i
            while j < self.n and self.inp[j] != 'W':
                j += 1

            j -= 1

            cnt_b = 0
            cnt_r = 0

            for k in range(i, j+1):
                if self.inp[k] == 'R':
                    cnt_r += 1
                else:
                    cnt_b += 1

            if cnt_r == 0 or cnt_b == 0:
                return "NO"

            i = j+1

        return "YES"


t = int(input())

while t:
    t -= 1

    cur = Solver1669D()

    print(cur.solve())