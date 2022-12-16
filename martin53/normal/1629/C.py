class Solver1629C:

    def __init__(self):
        self.n = int(input())
        self.inp = list(map(int, input().split(' ')))

    def solve(self):
        seen = [[] for _ in range(self.n+1)]
        for i in range(self.n-1, -1, -1):
            seen[self.inp[i]].append(i)

        output = []

        last_added = -1

        while len(seen[0]):
            mex = 0

            right = 0

            while len(seen[mex]):
                right = max(right, seen[mex][len(seen[mex])-1])
                mex += 1

            output.append(mex)
            last_added = right

            for i in range(mex):
                while len(seen[i]) and seen[i][len(seen[i])-1] <= right:
                    seen[i].pop()

        for i in range(last_added+1, self.n):
            output.append(0)

        print(len(output))

        for j in output:
            print(j, end=' ')

        print()


t = int(input())

while t:

    t -= 1

    cur = Solver1629C()

    cur.solve()