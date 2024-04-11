from math import sin, cos, pi, tan

l3, l4, l5 = map(int, input().split())

def f(n, x):
    R = 0.5 * x / sin(pi / n)
    h = (x**2 - R**2)**0.5
    base = n * R**2 * sin(2 * pi / n) * 0.5
    return base * h / 3


print(f(3, l3) + f(4,l4) + f(5,l5))