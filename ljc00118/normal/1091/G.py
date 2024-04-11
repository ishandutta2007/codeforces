import sys
import random
import math
# from math import *

n = int(input())

a = []
ans = [n]

def solve() :
    x = int(random.randint(1, 10 ** 18) % n)
    y = math.gcd(x, n)
    if y == 1 :
        print("sqrt", end = ' ')
        print(int((x * x) % n), end = '\n')
        sys.stdout.flush()
        t = int(input())
        if x == t or x + t == n or t == -1 :
            return
        t -= x;
        if t < 0 :
            t += n
        a.append(t)
    else :
        a.append(y)

for i in range(20) :
    solve()

for i in a :
    tmp = []
    for j in ans :
        x = math.gcd(i, j)
        if x != 1 and x != j :
            tmp.append(x)
            tmp.append(j // x)
        else :
            tmp.append(j)
    ans = tmp

ans.sort()

ansLen = len(ans)

print("!", end = ' ')

print(ansLen, end = ' ')

for i in ans :
    print(i, end = ' ')