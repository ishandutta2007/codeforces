class Solver1692F:

    def __init__(self):
        self.n = int(input())
        self.inp = list(map(int, input().split(' ')))

    def solve(self):
        cnt = [0 for _ in range(10)]

        for i in range(self.n):
            cnt[self.inp[i] % 10] += 1

        for i in range(10):
            for j in range(10):
                k = (23 - i - j) % 10
                cnt[i] -= 1
                cnt[j] -= 1
                cnt[k] -= 1

                if cnt[i] >= 0 and cnt[j] >= 0 and cnt[k] >= 0:
                    return "YES"

                cnt[i] += 1
                cnt[j] += 1
                cnt[k] += 1

        return "NO"

t = int(input())

while t:
    t -= 1

    cur = Solver1692F()

    print(cur.solve())