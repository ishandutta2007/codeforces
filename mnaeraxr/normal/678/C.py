def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)

def lcm(a, b):
    return a // gcd(a, b) * b

n, a, b, p, q = map(int, input().split())

print(n // a * p + n // b * q - n // lcm(a, b) * min(p, q))