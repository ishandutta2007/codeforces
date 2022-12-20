class Solver1659D:

    def __init__(self):
        self.n = int(input())
        self.inp = list(map(int, input().split(' ')))
        self.pref = [[0, 0] for _ in range(self.n)]
        self.outp = [0 for _ in range(self.n)]

    def solve(self):
        ones = sum(self.inp)//self.n

        for i in range(self.n-1, 0, -1):
            self.pref[i] = [i+1-ones, ones]

            ok = i-1
            not_ok = self.n

            while not_ok-ok > 1:
                av = (ok+not_ok)//2

                if self.pref[av][0] <= i:
                    ok = av
                else:
                    not_ok = av

            #print("i=",i,"ok=",ok,self.pref[i])

            self.outp[i] = (self.inp[i] - (ok - i + 1))//i

            ones -= self.outp[i]

        self.outp[0] = ones

        print(' '.join(map(str, self.outp)))


t = int(input())

while t:

    t -= 1

    cur = Solver1659D()

    cur.solve()