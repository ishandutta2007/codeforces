from sys import stdin
def input(): return stdin.readline().strip()


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(t):
    n = read_int()
    problems = [tuple(read_ints()) for _ in range(n)]
    hi = [0] * 11
    for b, d in problems:
        hi[d] = max(hi[d], b)
    if hi[1:].count(0):
        print('MOREPROBLEMS')
    else:
        print(sum(hi))