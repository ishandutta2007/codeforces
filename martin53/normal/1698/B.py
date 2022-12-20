class Solver1698B:

    def __init__(self):
        self.n, self.k = list(map(int, input().split(' ')))
        self.inp = list(map(int, input().split(' ')))

    def solve(self):

        if self.k == 1:
            return (self.n-1)//2

        output = 0

        for i in range(1, self.n-1):
            if self.inp[i] > self.inp[i-1] + self.inp[i+1]:
                output += 1

        return output


t = int(input())

while t:
    t -= 1

    cur = Solver1698B()

    print(cur.solve())