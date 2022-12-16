def eval(cur):
    if cur == 'R':
        return -1
    if cur == 'r':
        return 1
    if cur == 'G':
        return -2
    if cur == 'g':
        return 2
    if cur == 'B':
        return -3
    return 3

class Solver1644A:

    def __init__(self):
        self.inp = input()

    def solve(self):
        seen = [0, 0, 0, 0]

        for i in range(6):
            cur = eval(self.inp[i])

            if cur >= 0:
                seen[cur] = 1
            elif seen[-cur] == 0:
                return "NO"

        return "YES"


t = int(input())

while t:

    t -= 1

    cur = Solver1644A()

    print(cur.solve())