import sys
import random
from math import *

n = int(input())

l = []

for i in range(40):
    x = random.randint(1, 10 ** 18)
    x %= n
    print(x)
    y = gcd(x, n)
    if y == 1:
        print('sqrt', (x * x) % n)
        sys.stdout.flush()
        s = int(input())
        if s == x or s + x == n:
            continue
        s -= x
        if s < 0:
            s += n
        l.append(s)
    else:
        l.append(y)

a = [n]
for i in l:
    b = []
    for j in a:
        x = gcd(j, i)
        if x != 1 and x != j:
            b.append(x)
            b.append(j // x)
        else:
            b.append(j)
    a = b
a.sort()
print('!', len(a), *a)