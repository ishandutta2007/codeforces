n, m = map(int, input().split())
ar = []
while n:
    ar.append(n % m)
    n //= m
if len(ar) == len(set(ar)):
    print('YES')
else:
    print('NO')