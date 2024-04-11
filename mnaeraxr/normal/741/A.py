n = int(input())

L = list(map(int, input().split()))

def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

def lcm(a, b):
    return a // gcd(a, b) * b

if len(set(L)) < n:
    print(-1)
else:
    a = 1

    for i in range(n):
        if L[i] == 0: continue
        u = i
        c = 0
        while L[u] != 0:
            c += 1
            v = L[u] - 1
            L[u] = 0
            u = v

        if c % 2 == 0:
            c //= 2

        a = lcm(a, c)

    print(a)