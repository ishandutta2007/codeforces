n, m, a, b = [int(x) for x in raw_input().split()]
ans = min(n%m * b, (m - n%m)%m * a)
print ans