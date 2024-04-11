import sys
import math

f = sys.stdin
n,r = map(int, f.readline().split())

side = r
ang1 = math.pi / n
ang2 = math.pi / 2.0 / n
ang3 = math.pi - ang1 - ang2
subarea = side * side * math.sin(ang1) * math.sin(ang2) / math.sin(ang3)

print subarea * n