import sys
input = lambda: sys.stdin.readline().strip()

#from functools import lru_cache
# @lru_cache(maxsize = 100000)

ni = lambda: int(input())
nl = lambda: list(map(int, input().split()))

def solve():
    n = ni()
    u = [0] * (n + 1)
    for x in nl():
        u[x] += 1
    for i in range(n + 1):
        if u[i] >= 3:
            print(i)
            return
    print(-1)

tests = ni()
#tests = 1
for test in range(tests):
    solve()