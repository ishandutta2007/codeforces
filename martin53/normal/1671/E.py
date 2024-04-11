class Solver1671E:

    def __init__(self):
        self.p = int(input())
        self.n = (1<<self.p)
        self.inp = input()
        self.mod = 998244353
        self.mini = [[] for _ in range(self.n)]
        self.ways = [1 for _ in range(self.n)]

    def solve(self):
        for i in range(self.n//2-1, self.n-1):
            self.mini[i] = self.inp[i]

        for i in range(self.n//2-2, -1, -1):
            #print("i= ",i)

            self.ways[i] = self.ways[2*i+1]*self.ways[2*i+2] % self.mod

            if self.mini[2*i+1] != self.mini[2*i+2]:
                self.ways[i] = 2*self.ways[i] % self.mod

            self.mini[i] = self.inp[i] + min(self.mini[2*i+1]+self.mini[2*i+2], self.mini[2*i+2]+self.mini[2*i+1])

            #print("i= ",i,self.mini[i],self.ways[i])

        return self.ways[0]

cur = Solver1671E()

print(cur.solve())