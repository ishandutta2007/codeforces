class Solver1673A:

    def __init__(self):
        self.inp = input()
        self.n = len(self.inp)

    def solve(self):

        alice = sum(ord(self.inp[i])-ord('a')+1 for i in range(self.n))
        bob = 0

        if self.n % 2 == 1:
            bob = ord(min(self.inp[0], self.inp[self.n-1])) - ord('a')+1

        alice -= bob

        if alice > bob:
            print("Alice",alice-bob)
        else:
            print("Bob",bob-alice)


t = int(input())

while t:

    t -= 1

    cur = Solver1673A()

    cur.solve()