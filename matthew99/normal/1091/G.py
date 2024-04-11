import random
from sys import stdout
 
# https://rosettacode.org/wiki/Miller%E2%80%93Rabin_primality_test#Python
def is_Prime(n):
    """
    Miller-Rabin primality test.
 
    A return value of False means n is certainly not prime. A return value of
    True means n is very likely a prime.
    """
    if n!=int(n):
        return False
    n=int(n)
    #Miller-Rabin test for prime
    if n==0 or n==1 or n==4 or n==6 or n==8 or n==9:
        return False
 
    if n==2 or n==3 or n==5 or n==7:
        return True
    s = 0
    d = n-1
    while d%2==0:
        d>>=1
        s+=1
    assert(2**s * d == n-1)
 
    def trial_composite(a):
        if pow(a, d, n) == 1:
            return False
        for i in range(s):
            if pow(a, 2**i * d, n) == n-1:
                return False
        return True  
 
    for i in range(20):#number of trials 
        a = random.randrange(2, n)
        if trial_composite(a):
            return False
 
    return True  

def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a%b)

def findFactors(n, fac):
    if is_Prime(fac):
        return [fac]
    while True:
        x = random.randrange(n)
        if gcd(x, n) == 1:
            print("sqrt", (x*x)%n)
            stdout.flush()
            y = int(input())
            if y != -1:
                if (x+y)%fac != 0 and (x-y)%fac != 0:
                    return findFactors(n, gcd(x+y, fac)) + findFactors(n, gcd(abs(x-y), fac))

n = int(input())
l = findFactors(n, n)
l = list(set(l))
print("!", len(l), *l)
stdout.flush()