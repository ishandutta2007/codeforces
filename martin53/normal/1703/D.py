class Solver1703D:

    def __init__(self):
        self.n = int(input())
        self.inp = []

        for i in range(self.n):
            self.inp.append(input())

    def solve(self):
        dict = {}

        for i in self.inp:
            dict[i] = 1

        output = []

        for i in self.inp:
            cur = 0
            for j in range(0, len(i)-1):
                if dict.get(i[0:j+1:1], None) != None and dict.get(i[j+1:len(i):1]) != None:
                    cur = 1
                    break

            output.append(cur)

        return output


t = int(input())

while t:

    t -= 1

    cur = Solver1703D()

    print(''.join(map(str, cur.solve())))