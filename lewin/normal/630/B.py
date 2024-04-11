import sys
import math

f = sys.stdin

n,t = map(int, f.readline().split())

intervals = t/63070000.0

print n * math.pow(1.000000011, t)