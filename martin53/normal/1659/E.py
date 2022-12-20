import sys

input = sys.stdin.readline

def bit(w, b):
    if w & (1 << b):
        return 1
    return 0


class DSU:

    def __init__(self, n):
        self.n = n
        self.parent = [i for i in range(self.n)]
        self.SZ = [1 for _ in range(self.n)]

    def root(self, node):
        if self.parent[node] == node:
            return node
        self.parent[node] = self.root(self.parent[node])
        return self.parent[node]

    def merge(self, u, v):
        u = self.root(u)
        v = self.root(v)

        if u == v:
            return

        if self.SZ[u] < self.SZ[v]:
            temp = u
            u = v
            v = temp

        self.parent[v] = u
        self.SZ[u] += self.SZ[v]


class Solver1659E:

    def __init__(self):
        self.C = 30
        self.n, self.m = list(map(int, input().split(' ')))
        self.bit_i = [DSU(self.n) for _ in range(self.C)]
        self.bit_i_0 = [DSU(self.n) for _ in range(self.C)]
        self.one_works = [[0 for _ in range(self.n)] for _ in range(self.C)]

        for i in range(self.m):
            u, v, w = list(map(int, input().split(' ')))

            u -= 1
            v -= 1

            for j in range(self.C):
                if bit(w, j):
                    self.bit_i[j].merge(u, v)

                if bit(w, j) and bit(w, 0):
                    self.bit_i_0[j].merge(u, v)

                if bit(w, 0) == 0:
                    self.one_works[j][u] = 1
                    self.one_works[j][v] = 1

        for b in range(self.C):
            for i in range(self.n):
                if self.one_works[b][i] == 1:
                    self.one_works[b][self.bit_i_0[b].root(i)] = 1

        #print(self.one_works)

    def query(self):

        u, v = list(map(int, input().split(' ')))

        u -= 1
        v -= 1

        for b in range(self.C):
            if self.bit_i[b].root(u) == self.bit_i[b].root(v):
                return 0

        for b in range(1, self.C):
            if self.bit_i_0[b].root(u) == self.bit_i_0[b].root(v):
                #print("i_0=",b)
                return 1

            if self.one_works[b][self.bit_i_0[b].root(u)]:
                #print("one_works=",b,self.bit_i_0[b].root(u))
                return 1

        return 2


cur = Solver1659E()

q = int(input())

while q:

    q -= 1

    print(cur.query())