class Solver1675D:

    def __init__(self):
        self.n = int(input())
        self.parent = list(map(int, input().split(' ')))
        self.nxt = [0 for _ in range(self.n+1)]
        self.root = [1 for _ in range(self.n+1)]

    def solve(self):
        for i in range(self.n):
            if self.parent[i] != i+1 and self.nxt[self.parent[i]] == 0:

                self.nxt[self.parent[i]] = i+1
                self.root[i+1] = 0

        print(sum(self.root)-1)

        for i in range(1, self.n+1):
            if self.root[i]:
                outp = []

                j = i

                while self.nxt[j]:
                    outp.append(j)
                    j = self.nxt[j]

                outp.append(j)

                #print("i=",i,"outp= ",outp)

                print(len(outp))
                print(' '.join(map(str, outp)))


t = int(input())

while t:
    t -= 1

    cur = Solver1675D()

    cur.solve()