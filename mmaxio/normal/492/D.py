from fractions import gcd

n, x, y = map(int, input().split())
g = gcd(x, y)
x //= g
y //= g

a = sorted([y * i for i in range(1, x)] + [x * i for i in range(1, y)])

def f(n):
    n %= x + y
    if n == 0 or n == x + y - 1:
        return "Both"
    return "Vova" if a[n - 1] % x == 0 else "Vanya"

for _ in range(n):
    print(f(int(input())))