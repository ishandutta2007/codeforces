def eval_2(a, b):
    return 1 + a//2 + b//2


def eval_1(a, b):
    if a > b:
        temp = a
        a = b
        b = temp

    step_1 = min(b-a, (b+1)//2)

    a = a - step_1
    b = b - 2*step_1

    if b <= 0:
        return step_1

    return step_1 + (2*a+2)//3


class Solver1674E:

    def __init__(self):
        self.n = int(input())
        self.inp = list(map(int, input().split(' ')))

    def solve(self):
        alone = [(self.inp[_]+1)//2 for _ in range(self.n)]

        alone.sort()

        outp = alone[0]+alone[1]

        for i in range(2, self.n):
            outp = min(outp, eval_2(self.inp[i-2], self.inp[i]))

        for i in range(1, self.n):
            outp = min(outp, eval_1(self.inp[i-1], self.inp[i]))

        return outp


cur = Solver1674E()

print(cur.solve())