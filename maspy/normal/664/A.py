from math import gcd
a, b = map(int, input().split())
ANS = a
for x in range(a, b + 1):
    ANS = gcd(ANS, x)
    if ANS == 1:
        break
print(ANS)