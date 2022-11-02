P,D = map(int,raw_input().split())
ans = P
for x in [10**i for i in range(1,21)]:
    v = x-1; p = P-P%x
    if p+v > P:
        p -= x
    n = p+v
    if P-n > D: break
    ans = n
print ans