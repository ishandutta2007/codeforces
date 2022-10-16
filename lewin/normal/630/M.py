import sys
import math

f = sys.stdin

n = int(f.readline())

n %= 360

x0 = n
x1 = (n + 270) % 360
x2 = (n + 180) % 360
x3 = (n + 90) % 360

xm = min(x0,360-x0,x1,360-x1,x2,360-x2,x3,360-x3)
if x0 == xm or 360-x0 == xm:
	print 0
elif x1 == xm or 360-x1 == xm:
	print 1
elif x2 == xm or 360-x2 == xm:
	print 2
elif x3 == xm or 360-x3 == xm:
	print 3