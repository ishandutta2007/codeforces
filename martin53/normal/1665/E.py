import sys

input = sys.stdin.readline


class SegmentTree:

    def __init__(self, n):
        self.tree = [[0, 0] for _ in range(2*n)]
        self.n = n

    def set(self, pos, val):

        pos += self.n

        #print("set", self.n, pos)

        self.tree[pos] = [val, pos - self.n]

        while pos > 1:
            self.tree[pos >> 1] = min(self.tree[pos], self.tree[pos ^ 1])

            pos = pos >> 1

    def query(self, l, r):
        ret = [(1 << 31), 0]

        l += self.n
        r += self.n

        while l < r:
            if l & 1:
                ret = min(ret, self.tree[l])
                l += 1
            if r & 1:
                r -= 1
                ret = min(ret, self.tree[r])

            l = l >> 1
            r = r >> 1

        return ret


class Solver1665E:

    def __init__(self):
        self.C = 30
        self.n = int(input())
        self.inp = list(map(int, input().split(' ')))
        self.tree = SegmentTree(self.n)
        self.inf = (1 << (self.C+1))

    def query(self):
        l, r = list(map(int, input().split(' ')))

        l -= 1
        r -= 1

        take = min(self.C + 1, r - l + 1)

        ids = []

        output = self.inf

        for j in range(take):
            mini = self.tree.query(l, r+1)

            #print("mini= ", mini)

            if len(ids) >= 2 and mini[0] >= output:
                break

            for i in range(len(ids)):
                output = min(output, ids[i][0] | mini[0])

            ids.append(mini)

            self.tree.set(mini[1], self.inf)

        #print(ids)

        output = self.inf

        for i in range(len(ids)):
            for j in range(i + 1, len(ids)):

                if output <= ids[j][0]:
                    break

                output = min(output, ids[i][0] | ids[j][0])

        for i in range(len(ids)):
            self.tree.set(ids[i][1], self.inp[ids[i][1]])

        return output

    def solve(self):

        for i in range(self.n):
            self.tree.set(i, self.inp[i])

        q = int(input())

        while q:

            q -= 1

            print(self.query())


t = int(input())

while t:
    t -= 1

    cur = Solver1665E()

    cur.solve()