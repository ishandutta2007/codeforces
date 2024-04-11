import math

def gcd(a, b):
    if a == 0:
        return 0, 1, b
    x1, y1, g = gcd(b % a, a)
    x = y1 - x1 * (b // a)
    y = x1
    return x, y, g


def _ceil(u, v):
    if v < 0:
        return _ceil(-u, -v)
    return u // v if u % v == 0 else u // v + 1


def _floor(u, v):
    if v < 0:
        return _floor(-u, -v)
    return u // v


n, p, w, d = [int(x) for x in input().split()]


x0, y0, g = gcd(w, d)

if p % g != 0:
    print('-1')
    exit(0)

x0 *= (p // g)
y0 *= (p // g)

d //= g
w //= g

if d == w and x0 + y0 > n:
    print('-1')
    exit(0)

lk = _ceil(-x0 , d)
rk = _floor(y0 , w)

if d > w:
    rk = min(rk, _floor((n - x0 - y0) , (d - w)))
if d < w:
    lk = max(lk, _ceil((n - x0 - y0) , (d - w)))

if lk > rk:
    print('-1')
    exit(0)

# print(f'{lk} .. {rk}')

k0 = lk
x = x0 + k0 * d
y = y0 - k0 * w
z = n - x - y

# print(f'{x} {y} {z}')

print(f'{x} {y} {z}')