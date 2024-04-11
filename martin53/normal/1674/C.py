class Solver1674C:

    def __init__(self):
        self.s = input()
        self.t = input()

    def solve(self):
        if self.t == 'a':
            return 1

        if 'a' in self.t:
            return -1

        return 1 << len(self.s)


t = int(input())

while t:
    t -= 1

    cur = Solver1674C()

    print(cur.solve())