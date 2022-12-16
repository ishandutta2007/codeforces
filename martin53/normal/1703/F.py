class Solver1703F:

    def __init__(self):
        self.n = int(input())
        self.inp = list(map(int, input().split(' ')))
        self.inp.insert(0, 0)

    def solve(self):
        pref = [0]

        for i in range(1, self.n+1):
            pref.append(pref[i-1])

            if self.inp[i] < i:
                pref[i] += 1

        output = 0

        for j in range(self.n+1):
            if self.inp[j] < j and self.inp[j] > 0:
                output += pref[self.inp[j]-1]

        return output


t = int(input())

while t:

    t -= 1

    cur = Solver1703F()

    print(cur.solve())