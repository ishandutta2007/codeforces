class Solver1702B:

    def __init__(self):
        self.inp = input()

    def solve(self):
        days = 0

        i = 0

        while i < len(self.inp):
            days += 1

            dict = {}

            while i < len(self.inp):
                dict[self.inp[i]] = 1

                if len(dict) > 3:
                    break

                i += 1

        return days


t = int(input())

while t:

    t -= 1

    cur = Solver1702B()

    print(cur.solve())