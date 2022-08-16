import sys
input = lambda: sys.stdin.readline().strip()

#from functools import lru_cache
# @lru_cache(maxsize = 100000)

ni = lambda: int(input())
nl = lambda: list(map(int, input().split()))

def solve():
    n = ni()
    m = ord('k') - ord('a') + 1
    u = [[0 for i in range(m)] for j in range(m)]
    for i in range(n):
        s = input()
        x = ord(s[0]) - ord('a')
        y = ord(s[1]) - ord('a')
        u[x][y] += 1
    res = 0
    for i in range(m):
        for x in range(m):
            for y in range(x + 1, m):
                res += u[i][x] * u[i][y]
                res += u[x][i] * u[y][i]
    print(res)

tests = ni()
#tests = 1
for test in range(tests):
    solve()