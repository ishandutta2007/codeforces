def solve(n, g, b):
    ng = (n+1) // 2
    full = ng // g
    time = full * (g+b) - b
    bads = b * (full-1)
    if ng % g:
        time += b + ng % g
        bads += b
    if bads < n - ng:
        time += (n-ng) - bads
    return time

n = int(raw_input())
for i in range(n):
    n, g, b = [int(x) for x in raw_input().split()]
    print solve(n, g, b)