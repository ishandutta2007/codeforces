import sys
input = lambda: sys.stdin.readline().strip()

#from functools import lru_cache
# @lru_cache(maxsize = 100000)

ni = lambda: int(input())
nl = lambda: list(map(int, input().split()))

def solve():
    n = ni()
    for s in input().split("W"):
        if len(s) == 0:
            continue
        flag = 0
        for i in range(1, len(s)):
            if s[i] != s[i - 1]:
                flag = 1
                break
        if flag == 0:
            print("No")
            return
    print("Yes")

tests = ni()
#tests = 1
for test in range(tests):
    solve()