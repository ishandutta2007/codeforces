class Solve1660F:

    def __init__(self):
        self.n = int(input())
        self.inp = input()

    def eval(self, prefix):

        if len(prefix) == 0:
            return 0

        cnt = [0 for _ in range(2*self.n + 1)]

        ret = 0

        active = 0
        pointer = prefix[0]

        for j in range(len(prefix)):
            while pointer < prefix[j]:
                active -= cnt[pointer]
                pointer += 1

            while pointer > prefix[j]:
                pointer -= 1
                active += cnt[pointer]

            ret += active

            cnt[prefix[j]] += 1
            active += 1

        return ret

    def solve(self):
        pref_sum = self.n

        pref = [[] for _ in range(3)]

        pref[pref_sum % 3].append(pref_sum)

        for i in range(self.n):
            if self.inp[i] == '+':
                pref_sum += 1
            else:
                pref_sum -= 1
            pref[pref_sum % 3].append(pref_sum)

        output = self.eval(pref[0])+self.eval(pref[1])+self.eval(pref[2])

        return output


t = int(input())

while t:
    t -= 1

    cur = Solve1660F()

    print(cur.solve())