n,m = map(int, raw_input().split())
ans = 100000000000
for i in range(n):
    a,b = map(int, raw_input().split())
    ans = min(ans, 1.0 * a * m / b)
print ans