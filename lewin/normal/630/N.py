import sys
import math

f = sys.stdin

a,b,c = map(int, f.readline().split())

x1 = (-b+math.sqrt(b*b-4*a*c))/(2.0*a)
x2 = (-b-math.sqrt(b*b-4*a*c))/(2.0*a)

a1 = max(x1,x2)
a2 = min(x1,x2)

print '{0:.15f}'.format(a1)
print '{0:.15f}'.format(a2)