class Solver1654B:

    def __init__(self):
        self.inp = input()
        self.n = len(self.inp)

    def solve(self):
        cnt = [0 for _ in range(26)]
        for i in range(self.n):
            cnt[ord(self.inp[i])-ord('a')] += 1

        #print(cnt)

        for i in range(self.n):
            if cnt[ord(self.inp[i])-ord('a')] == 1:
                for j in range(i, self.n):
                    print(self.inp[j], end='')
                print()
                return
            else:
                cnt[ord(self.inp[i]) - ord('a')] -= 1

t = int(input())

while t:

    t -= 1

    cur = Solver1654B()

    cur.solve()