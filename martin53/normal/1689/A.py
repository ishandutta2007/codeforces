class Solver1689A:

    def __init__(self):
        self.n, self.m, self.k = list(map(int, input().split(' ')))
        self.a = input()
        self.b = input()

    def solve(self):
        cnt_a = [ord(self.a[i]) for i in range(self.n)]
        cnt_a.sort()

        cnt_b = [ord(self.b[i]) for i in range(self.m)]
        cnt_b.sort()

        prv = 0
        cnt = 0

        pointer_a = 0
        pointer_b = 0

        while pointer_a < self.n and pointer_b < self.m:

            use = 0

            if prv == 0 and cnt == self.k:
                use = 1
            elif cnt != self.k and cnt_a[pointer_a] > cnt_b[pointer_b]:
                use = 1

            if use == 1:
                print(chr(cnt_b[pointer_b]), end='')
                pointer_b += 1

                if prv == 0:
                    prv = 1
                    cnt = 1
                else:
                    cnt += 1

            else:
                print(chr(cnt_a[pointer_a]), end='')
                pointer_a += 1

                if prv == 1:
                    prv = 0
                    cnt = 1
                else:
                    cnt += 1

        print()


t = int(input())

while t:
    t -= 1

    cur = Solver1689A()

    cur.solve()