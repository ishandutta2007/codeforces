class Solve1660F:

    def __init__(self):
        self.n = int(input())
        self.inp = input()

    def solve(self):
        pref_sum = self.n

        pref = []

        pref.append(pref_sum)

        for i in range(self.n):
            if self.inp[i] == '+':
                pref_sum += 1
            else:
                pref_sum -= 1
            pref.append(pref_sum)

        output = 0

        for i in range(len(pref)):
            for j in range(i+1, len(pref)):
                if pref[i] % 3 == pref[j] % 3 and pref[i] >= pref[j]:
                    output += 1

        return output


t = int(input())

while t:
    t -= 1

    cur = Solve1660F()

    print(cur.solve())