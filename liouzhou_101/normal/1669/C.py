import sys
input = lambda: sys.stdin.readline().strip()

#from functools import lru_cache
# @lru_cache(maxsize = 100000)

ni = lambda: int(input())
nl = lambda: list(map(int, input().split()))

def solve():
    n = ni()
    a = nl()
    for i in range(n):
        for j in range(i + 1, n):
            if i % 2 == j % 2:
                if a[i] % 2 != a[j] % 2:
                    print("No")
                    return
    print("Yes")

tests = ni()
#tests = 1
for test in range(tests):
    solve()