class Solver1665C:

    def __init__(self):
        self.n = int(input())
        self.parent = list(map(int, input().split(' ')))

    def solve(self):
        degree = [0 for _ in range(self.n+1)]
        for i in range(self.n-1):
            degree[self.parent[i]] += 1

        degs = []
        for i in range(self.n+1):
            if degree[i]:
                degs.append(degree[i])

        degs.sort()

        for i in range(len(degs)):
            degs[i] = degs[i] - i - 1

        ok = self.n
        not_ok = 0

        while ok - not_ok > 1:
            av = (ok+not_ok)//2

            need = 1

            for i in range(len(degs)):
                need += max(0, degs[i] - av)

            if need <= av:
                ok = av
            else:
                not_ok = av

        return ok + len(degs)


t = int(input())

while t:
    t -= 1

    cur = Solver1665C()

    print(cur.solve())