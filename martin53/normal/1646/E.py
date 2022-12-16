class Solver1646E:

    def __init__(self):
        self.n, self.m = list(map(int, input().split(' ')))
        self.been = [0 for _ in range(self.n+1)]

    def solve(self):

        steps = 0

        while (1 << steps) <= self.n:
            steps += 1

        steps -= 1

        unique = [0 for _ in range(steps+1)]

        for num in range(1, steps*self.m+1):
            for s in range((num+self.m-1)//self.m, steps+1):
                if num % s == 0 and num//s <= self.m:
                    unique[s] += 1
                    break

        for i in range(1, len(unique)):
            unique[i] += unique[i-1]

        output = 1

        for i in range(2, self.n+1):
            if self.been[i] == 0:
                cnt = 0
                j = i

                while j <= self.n:
                    self.been[j] = 1
                    cnt += 1
                    j = j*i

                output += unique[cnt]

        return output


cur = Solver1646E()

print(cur.solve())