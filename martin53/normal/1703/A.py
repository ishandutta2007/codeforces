class Solver1703A:

    def __init__(self):
        self.inp = input()

    def solve(self):
        if self.inp.upper()=='YES':
            return 'YES'
        return 'NO'


t = int(input())

while t:

    t-=1

    cur = Solver1703A()

    print(cur.solve())