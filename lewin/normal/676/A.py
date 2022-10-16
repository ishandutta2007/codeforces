import sys

n = int(sys.stdin.readline())
arr = map(int, sys.stdin.readline().split())

p1 = arr.index(1)
pn = arr.index(n)

print max([p1, n-1-p1, pn, n-1-pn])