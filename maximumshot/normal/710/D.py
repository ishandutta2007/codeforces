import math 

# g, x, y
def gcd(a, b) :
    if a == 0 :
        return [b, 0, 1]
    l = gcd(b % a, a)
    g, x1, y1 = [int(i) for i in l]
    x = y1 - (b // a) * x1
    y = x1
    return [g, x, y]

def my_ceil(u, v) :
    if v < 0 :
        u *= -1
        v *= -1
    return math.ceil(u / v)

def my_floor(u, v) :
    if v < 0 :
        u *= -1
        v *= -1
    return math.floor(u / v)

a1, b1, a2, b2, L, R = [int(i) for i in input().split()]
A = a1
B = -a2
C = b2 - b1
g, x0, y0 = [int(i) for i in gcd(abs(A), abs(B))]

if A < 0 : x0 *= -1
if B < 0 : y0 *= -1

if C % g != 0 :
    print(0)
    exit()

x0 *= C // g
y0 *= C // g

le = max([
    float(R - b1 - a1 * x0) / float(a1 * B // g),
    float(y0 * a2 + b2 - R) / float(a2 * A // g)
    ])

ri = min([
    float(L - b1 - a1 * x0) / float(a1 * B // g),
    float(y0 * a2 + b2 - L) / float(a2 * A // g),
    float(-x0) / float(B // g),
    float(y0) / float(A // g)
    ])

le = int(math.ceil(le))
ri = int(math.floor(ri))

if ri - le + 1 <= 10000 :
    result = 0
    for k in range(le - 100, ri + 101) :
        X = x0 + B * k // g
        Y = y0 - A * k // g
        if X >= 0 and Y >= 0 and a1 * X + b1 >= L and a1 * X + b1 <= R :
            result += 1
    print(result)
else : 
    print(max(int(0), ri - le + 1))