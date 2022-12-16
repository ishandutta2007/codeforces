

class solver1680C:

    def __init__(self):
        self.inp = input()
        self.pref = []
        self.n = len(self.inp)

    def eval_pref(self, l, r):

        if l > r:
            return 0

        ret = self.pref[r]

        if l:
            ret = ret - self.pref[l-1]

        #print(l,r,ret)

        return ret

    def eval(self, l, r):
        cnt_0 = r-l+1-self.eval_pref(l, r)
        cnt_1 = self.eval_pref(0, l-1)+self.eval_pref(r+1, self.n-1)

        return [cnt_0, cnt_1]

    def solve(self):
        pref_sum = 0

        for i in self.inp:
            if i == '1':
                pref_sum += 1
            self.pref.append(pref_sum)

        #print(self.pref)

        outp = self.n

        l = 0

        r = -1

        while l < self.n:

            while r < self.n:
                cur = self.eval(l, r)

                #print(l,r,cur)

                outp = min(outp, max(cur))

                if cur[0] < cur[1]:
                    r = r+1
                else:
                    break

            l = l+1

            r = max(l, r)

        return outp


t = int(input())

while t:
    t = t-1

    cur = solver1680C()

    print(cur.solve())