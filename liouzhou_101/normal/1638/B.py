import sys
input = sys.stdin.readline

#from functools import lru_cache
# @lru_cache(maxsize = 100000)

ni = lambda: int(input())
nl = lambda: list(map(int, input().split()))

def solve():
    n = ni()
    a = nl()
    p = []
    q = []
    for x in a:
        if x % 2 == 0:
            p.append(x)
        else:
            q.append(x)
    if sorted(p) == p and sorted(q) == q:
        print("Yes")
    else:
        print("No")
tests = ni()
for test in range(tests):
    solve()