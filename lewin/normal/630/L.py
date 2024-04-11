import sys
import math

f = sys.stdin

n = int(f.readline())
d1 = (n/10000)%10
d2 = (n/1000)%10
d3 = (n/100)%10
d4 = (n/10)%10
d5 = n%10

n = d1*10000 + d3*1000 + d5*100 + d4 * 10 + d2

n = n * n * n * n * n
s = str(n % 100000)
while len(s) < 5:
	s = "0" + s
print s