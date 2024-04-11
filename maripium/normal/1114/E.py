import sys
from math import gcd
from random import randint

def get1(x):
    print('?', x + 1)
    sys.stdout.flush()
    ans = int(input())
    return ans
def get2(x):
    print('>', x)
    sys.stdout.flush()
    ans = int(input())
    return ans
n = int(input())
l = 0
r = 10 ** 9
while (l < r):
    md = (l + r) >> 1
    if (get2(md)):
        l = md + 1
    else :
        r = md
d = 0
for i in range(30):
    x = randint(0, n - 1)
    x = get1(x)
    if (x < r): 
        d = gcd(d, r - x)
print('!', r - (n - 1) * d, d)