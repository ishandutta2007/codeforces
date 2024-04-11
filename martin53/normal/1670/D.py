import math

import sys

input = sys.stdin.readline

class Solver1670D:

    def __init__(self):
        self.n = int(input())

    def solve(self):

        return math.ceil(math.sqrt(self.n*3.0/2))


t = int(input())

while t:
    t -= 1

    cur = Solver1670D()

    print(cur.solve())