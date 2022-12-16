class Solver1702D:

    def __init__(self):
        self.inp = input()
        self.p = int(input())

    def solve(self):
        cnt = [0] * 27

        score = 0

        for i in self.inp:
            cnt[ord(i)-ord('a')+1] += 1
            score += ord(i)-ord('a')+1

        for i in range(26, 0, -1):
            while cnt[i] and score > self.p:
                cnt[i] -= 1
                score -= i

        for i in self.inp:
            if cnt[ord(i)-ord('a')+1]:
                print(i, end='')
                cnt[ord(i) - ord('a') + 1] -= 1

        print()


t = int(input())

while t:

    t -= 1

    cur = Solver1702D()

    cur.solve()