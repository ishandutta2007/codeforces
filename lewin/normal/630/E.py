import sys
import math

f = sys.stdin

x1,y1,x2,y2 = map(int, f.readline().split())

dx = abs(x1-x2)
dy = abs(y1-y2)

size = dx / 2 + 1
nbig = (dy+2)/2
nsmall = (dy+1)/2
print nbig * size + nsmall * (size - 1)