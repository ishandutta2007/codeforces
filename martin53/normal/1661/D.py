import sys

input = sys.stdin.readline


class SegmentTree:

    def __init__(self, n):
        self.n = n
        self.lazy_a = [0 for _ in range(4*n)]
        self.lazy_b = [0 for _ in range(4*n)]

        #print(self.lazy_a, self.lazy_b)
        # i -> lazy_b+i*lazy_a

    def push(self, node, l, r):
        av = (l+r)//2

        self.lazy_a[node*2] += self.lazy_a[node]
        self.lazy_b[node*2] += self.lazy_b[node]

        self.lazy_a[node*2+1] += self.lazy_a[node]
        self.lazy_b[node*2+1] += self.lazy_b[node] + (av+1-l)*self.lazy_a[node]

        self.lazy_a[node] = 0
        self.lazy_b[node] = 0

    def update(self, node, l, r, lq, rq, a, b):

        #print("update", node, l, r, lq, rq, a, b)

        if l == lq and r == rq:
            self.lazy_a[node] += a
            self.lazy_b[node] += b
            return

        self.push(node, l, r)

        av = (l+r)//2

        if lq <= av:
            self.update(node*2, l, av, lq, min(av, rq), a, b)

        if av+1 <= rq:
            self.update(node*2+1, av+1, r, max(av+1, lq), rq, a, b+a*max(0, av+1-lq))

    def query(self, node, l, r, pos):
        if l == r:
            return self.lazy_b[node]

        self.push(node, l, r)

        av = (l+r)//2

        if pos <= av:
            return self.query(node*2, l, av, pos)

        return self.query(node*2+1, av+1, r, pos)


class Solve1661D:

    def __init__(self):
        self.n, self.k = list(map(int, input().split(' ')))
        self.inp = list(map(int, input().split(' ')))

    def solve(self):
        tree = SegmentTree(self.n)

        output = 0

        for i in range(self.n-1, -1, -1):
            diff = self.inp[i] - tree.query(1, 0, self.n-1, i)

            diff = max(diff, 0)

            start = max(0, i-self.k+1)

            apply = (diff + i - start + 1 - 1)//(i - start + 1)

            #print("i=", i, "apply=", apply)

            output += apply

            tree.update(1, 0, self.n-1, start, start+self.k-1, apply, apply)

        return output


cur = Solve1661D()

print(cur.solve())