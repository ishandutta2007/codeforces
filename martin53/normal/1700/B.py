class Solver1700B:

    def __init__(self):
        self.n = int(input())
        self.inp = int(input())

    def solve(self):

        pwr = (10**(self.n-1))

        num = 10*pwr - 1 - self.inp

        if num >= pwr:
            return num

        return (100*pwr-1)//9 - self.inp


t = int(input())

while t:
    t -= 1

    cur = Solver1700B()

    print(cur.solve())