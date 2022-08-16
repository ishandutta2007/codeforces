import sys
input = lambda: sys.stdin.readline().strip()

#from functools import lru_cache
# @lru_cache(maxsize = 100000)

ni = lambda: int(input())
nl = lambda: list(map(int, input().split()))

def solve():
    n = ni()
    if n <= 1399:
        print("Division 4")
    elif n <= 1599:
        print("Division 3")
    elif n <= 1899:
        print("Division 2")
    else:
        print("Division 1")
    pass

tests = ni()
#tests = 1
for test in range(tests):
    solve()