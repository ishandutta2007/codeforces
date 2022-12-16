class Solver1660D:

    def __init__(self):
        self.n = int(input())
        self.inp = list(map(int, input().split(' ')))

    def solve(self):
        x = 0
        y = self.n
        score = 0

        i = 0
        while i < self.n:
            if self.inp[i] == 0:
                i += 1
                continue

            j = i
            while j < self.n and self.inp[j] != 0:
                j += 1

            j -= 1

            two = 0
            sign = 1

            for k in range(i, j+1):
                if abs(self.inp[k]) == 2:
                    two += 1
                if self.inp[k] < 0:
                    sign = -sign

            if sign > 0:
                if two > score:
                    score = two
                    x = i
                    y = self.n - 1 - j
            else:
                #left
                two_sub = 0
                sign_sub = 0

                p = i

                while sign_sub == 0:
                    if abs(self.inp[p]) == 2:
                        two_sub += 1

                    if self.inp[p] < 0:
                        sign_sub = 1

                    p += 1

                if two - two_sub > score:
                    score = two - two_sub
                    x = p
                    y = self.n - 1 - j
                #right
                two_sub = 0
                sign_sub = 0

                q = j

                while sign_sub == 0:
                    if abs(self.inp[q]) == 2:
                        two_sub += 1

                    if self.inp[q] < 0:
                        sign_sub = 1

                    q -= 1

                if two - two_sub > score:
                    score = two - two_sub
                    x = i
                    y = self.n - q - 1

            i = j + 1

            #print("i=", i, "x=", x, "y= ", y, "score=", score)

        print(x, y)


t = int(input())

while t:

    t -= 1

    cur = Solver1660D()

    cur.solve()