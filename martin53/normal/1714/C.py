class Solver1714C:

    def __init__(self):
        self.s = int(input())

    def solve(self):

        arr = []

        for i in range(9, 0, -1):
            if self.s >= i:
                self.s = self.s - i
                arr.append(i)

        arr = arr[::-1]

        print(''.join(map(str, arr)))


t = int(input())

while t:

    t -= 1

    cur = Solver1714C()

    cur.solve()