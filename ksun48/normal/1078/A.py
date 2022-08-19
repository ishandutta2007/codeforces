from sys import stdin
from math import hypot

line1 = stdin.readline().split()
line2 = stdin.readline().split()
Ax, Ay, Bx, By = [ int(x) for x in line2]
P, Q, R = [ float(x) for x in line1]
P = P + 1e-12
Q = Q + 1e-12

R = -R
result = abs(Ax - Bx) + abs(Ay - By)
Axx, Ayy = (R-Q*Ay)/P, (R-P*Ax)/Q
Bxx, Byy = (R-Q*By)/P, (R-P*Bx)/Q
result = min( result, abs(Ax - Axx) + abs(Bx - Bxx) + hypot(Axx-Bxx, Ay-By) )
result = min( result, abs(Ax - Axx) + abs(By - Byy) + hypot(Axx-Bx, Ay-Byy) )
result = min( result, abs(Ay - Ayy) + abs(Bx - Bxx) + hypot(Ax-Bxx, Ayy-By) )
result = min( result, abs(Ay - Ayy) + abs(By - Byy) + hypot(Ax-Bx, Ayy-Byy) )
print "%.10f" % result