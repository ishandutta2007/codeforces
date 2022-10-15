from math import *
T = int(input())
while T > 0:
    n = int(input())
    print(100 // gcd(n, 100))
    T -= 1