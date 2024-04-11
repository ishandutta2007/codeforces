class Solver1659B:

    def __init__(self):
        self.n, self.k = list(map(int, input().split(' ')))
        self.str = input()
        self.inp = []
        
        for i in range(self.n):
            self.inp.append(ord(self.str[i])-ord('0'))

    def solve(self):

        k_remain = self.k

        outp = []

        for i in range(self.n):
            cur = (self.k + self.inp[i] + 1) % 2
            cur = min(cur, k_remain)

            if i == self.n-1:
                cur = k_remain % 2

            outp.append(cur)
            k_remain -= cur

        outp[0] += k_remain

        for i in range(self.n):
            self.inp[i] = (self.inp[i]+self.k-outp[i]) % 2

        print(''.join(map(str, self.inp)))
        print(' '.join(map(str, outp)))


t = int(input())

while t:
    t -= 1

    cur = Solver1659B()

    cur.solve()