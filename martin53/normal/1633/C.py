class Solver1633C:

    def __init__(self):
        self.hc, self.dc = list(map(int, input().split(' ')))
        self.hm, self.dm = list(map(int, input().split(' ')))
        self.k, self.w, self.a = list(map(int, input().split(' ')))

    def solve(self):
        for i in range(self.k+1):
            health = self.hc + i * self.a
            damage = self.dc + (self.k - i) * self.w

            moves = (self.hm + damage - 1) // damage
            monster_moves = (health + self.dm - 1) // self.dm

            if moves <= monster_moves:
                return "YES"

        return "NO"


t = int(input())

while t:

    t -= 1

    cur = Solver1633C()

    print(cur.solve())