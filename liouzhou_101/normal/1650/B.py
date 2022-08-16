import sys
input = sys.stdin.readline

#from functools import lru_cache
# @lru_cache(maxsize = 100000)

ni = lambda: int(input())
nl = lambda: list(map(int, input().split()))

def solve():
    l, r, a = nl()

    def calc(x):
        return x // a + x % a

    res = calc(r)
    x = r // a * a - 1
    if l <= x and x <= r:
        res = max(res, calc(x))
    print(res)

tests = ni()
#tests = 1
for test in range(tests):
    solve()