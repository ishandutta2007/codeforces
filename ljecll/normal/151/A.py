n, k, l, c, d, p, nl, np = map(int, input().split())

print(min(k * l // (n * nl), c * d // n, p // (np * n)))