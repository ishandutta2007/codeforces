class Solver1629D:

    def __init__(self):
        self.n = int(input())
        self.inp = [[] for _ in range(self.n)]

        for i in range(self.n):
            self.inp[i] = input()

    def solve(self):
        for current in self.inp:
            if current == current[::-1]:
                return 'YES'

        seen_2 = {}
        seen_3 = {}

        for current in self.inp:
            if len(current) == 2:

                bck = current[1] + current[0]

                if seen_2.get(bck, None) != None or seen_3.get(bck, None) != None:
                    return 'YES'

                seen_2[current] = 1
            else:
                bck = current[2] + current[1] + current[0]

                if seen_3.get(bck, None) != None:
                    return 'YES'

                seen_3[current] = 1

                bck = current[2] + current[1]

                if seen_2.get(bck, None) != None:
                    return 'YES'

                seen_3[current[0] + current[1]] = 1

        return 'NO'


t = int(input())

while t:

    t -= 1

    cur = Solver1629D()

    print(cur.solve())