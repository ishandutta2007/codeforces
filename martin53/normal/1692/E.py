class Solve1692E:

    def __init__(self):
        self.n, self.s = list(map(int, input().split(' ')))
        self.inp = list(map(int, input().split(' ')))

    def solve(self):

        output = self.n + 1

        j = -1

        sum = 0

        for i in range(self.n):
            while j+1 < self.n and sum+self.inp[j+1] <= self.s:
                j += 1
                sum += self.inp[j]

                if sum == self.s:
                    output = min(output, self.n - (j-i+1))

            sum -= self.inp[i]

        if output > self.n:
            return -1

        return output


t = int(input())

while t:

    t -= 1

    cur = Solve1692E()

    print(cur.solve())