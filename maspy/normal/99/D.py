"""
1/n = sum c_k 2^{-k} n * sum kc_k2^{-k} 
"""

from fractions import Fraction

def f(N):
    n = 0
    while N % 2 == 0:
        N//=2
        n+=1
    if N==1:
        return Fraction(n,1)
    
    C = []
    x = 1
    while True:
        x = 2 * x
        C.append(x//N)
        x %= N
        if x == 1:
            break
    P = len(C)
    C = C[::-1]
    a = b = 0
    for k, x in enumerate(C):
        a += x<<k
        b += ((P-k)*x)<<k
    x = Fraction(P*a,((1<<P)-1)**2)
    y = Fraction(b,(1<<P)-1)
    ANS = (x + y) * N
    ANS += n
    return ANS

N = int(input())
ANS = f(N)
print(f"{ANS.numerator}/{ANS.denominator}")