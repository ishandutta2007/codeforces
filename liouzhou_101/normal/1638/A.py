#from functools import lru_cache
# @lru_cache(maxsize = 100000)

ni = lambda: int(input())
nl = lambda: list(map(int, input().split()))

def solve():
    n = ni()
    p = nl()
    for i in range(n):
        if p[i] != i + 1:
            for j in range(i, n):
                if p[j] == i + 1:
                    p = p[:i] + (p[i:j+1])[::-1] + p[j+1:]
                    break
            break
    print(*p)

tests = ni()
for test in range(tests):
    solve()