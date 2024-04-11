def ask(l, r):
    print('?', l, r)

    ret = list(map(int, input().split(' ')))

    return ret


def take_actual(l, r, active):
    actual_active = []

    for i in range(len(active)):
        if l <= active[i] and active[i] <= r:
            actual_active.append(active[i])

    return actual_active


class Solver1698D:

    def __init__(self):
        self.n = int(input())

    def rec(self, l, r, active):

        active = take_actual(l, r, active)

        if len(active) == 1:
            return active[0]

        av = (l+r)//2

        cur = take_actual(l, av, ask(l, av))

        if len(cur) % 2 == 1:
            return self.rec(l, av, cur)

        return self.rec(av+1, r, active)

    def solve(self):
        active = [i for i in range(1, self.n+1)]

        return self.rec(1, self.n, active)


t = int(input())

while t:

    t -= 1

    cur = Solver1698D()

    print('!', cur.solve())