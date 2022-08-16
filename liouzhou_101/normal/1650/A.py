import sys
#input = sys.stdin.readline

#from functools import lru_cache
# @lru_cache(maxsize = 100000)

ni = lambda: int(input())
nl = lambda: list(map(int, input().split()))

def solve():
    s = input()
    c = input()
    for i, x in enumerate(s):
        if x == c:
            if i % 2 == 0:
                print("Yes")
                return
    print("No")

tests = ni()
#tests = 1
for test in range(tests):
    solve()