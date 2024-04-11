import sys
import math

f = sys.stdin

n = int(f.readline())
div2 = n // 2
div3 = n // 3
div5 = n // 5
div7 = n // 7

div6 = n // 6
div10 = n // 10
div14 = n // 14
div15 = n // 15
div21 = n // 21
div35 = n // 35

div30 = n // 30
div42 = n // 42
div70 = n // 70
div105 = n // 105

div210 = n // 210

print n-(div2+div3+div5+div7-div6-div10-div14-div15-div21-div35+div30+div42+div70+div105-div210)