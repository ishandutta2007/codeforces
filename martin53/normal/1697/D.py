def ask_1(i):
    print("?", 1, i)

    letter = input()

    return letter


def ask_2(l, r):
    print("?", 2, l, r)

    return int(input())


class Solver1697D:

    def __init__(self):
        self.n = int(input())

    def solve(self):
        outp = []

        prv = 0

        seen = [-1 for _ in range(26)]

        for i in range(self.n):

            active = []

            for j in range(26):
                if seen[j] != -1:
                    active.append(seen[j])

            active.sort()

            cur = ask_2(1, i+1)

            if prv != cur:
                letter = ask_1(i+1)

                outp.append(letter)
            else:
                ok = 0
                not_ok = len(active)

                while not_ok - ok > 1:
                    av = (ok+not_ok)//2

                    if ask_2(active[av]+1, i+1) == len(active) - av:
                        ok = av
                    else:
                        not_ok = av

                outp.append(outp[active[ok]])

            prv = cur

            seen[ord(outp[i])-ord('a')] = i

        #print("outp=", outp)

        print("! ", end='')
        for i in range(self.n):
            print(outp[i], end='')
        print()


cur = Solver1697D()

cur.solve()