class Solver1692G:

    def __init__(self):
        self.n, self.k = list(map(int, input().split(' ')))
        self.inp = list(map(int, input().split(' ')))

    def solve(self):

        pref = []

        pref_sum = 0

        for i in range(self.n-1):
            if self.inp[i] >= 2*self.inp[i+1]:
                pref_sum += 1
            pref.append(pref_sum)

        output = 0

        for i in range(self.n-self.k):
            ones = 0

            if i + self.k - 1 >= 0:
                ones += pref[i+self.k-1]
            if i - 1 >= 0:
                ones -= pref[i-1]

            if ones == 0:
                output += 1

        return output


t = int(input())

while t:

    t -= 1

    cur = Solver1692G()

    print(cur.solve())