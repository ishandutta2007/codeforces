import sys
from bisect import bisect_right

f = sys.stdin

f.readline()
a = sorted(map(int, f.readline().split()))
b = map(int, f.readline().split())
print " ".join([str(bisect_right(a, x)) for x in b])