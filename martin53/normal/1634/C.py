class Solver1634C:

    def __init__(self):
        self.n, self.k = list(map(int, input().split(' ')))

    def solve(self):
        if self.n % 2 == 0 or self.k == 1:
            print('YES')
            for i in range(1, self.n+1):
                for j in range(self.k):
                    print((i-1)//2 * (2*self.k) + 1 + (i-1) % 2 + 2 * j, end=' ')
                print()
        else:
            print('NO')


t = int(input())

while t:

    t -= 1

    cur = Solver1634C()

    cur.solve()