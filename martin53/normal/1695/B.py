class Solver1695B:

    def __init__(self):
        self.n = int(input())
        self.inp = list(map(int, input().split(' ')))

    def solve(self):
        if self.n % 2 == 1:
            return "Mike"

        id_mike = 0

        for i in range(0, self.n, 2):
            if self.inp[i] < self.inp[id_mike]:
                id_mike = i

        id_joe = 0
        for i in range(1, self.n, 2):
            if self.inp[i] < self.inp[id_joe]:
                id_joe = i

        if self.inp[id_joe] < self.inp[id_mike]:
            return "Mike"

        if self.inp[id_joe] == self.inp[id_mike] and id_joe < id_mike:
            return "Mike"

        return "Joe"


t = int(input())

while t:

    t -= 1

    cur = Solver1695B()

    print(cur.solve())