import sys
from bisect import bisect
f = lambda : sys.stdin.readline()
f()
print (lambda arr: "\n".join(str(bisect(arr, int(f()))) for _ in range(int(f()))))(sorted(map(int, f().split())))