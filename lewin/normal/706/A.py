import sys
import math
f = lambda : sys.stdin.readline()
print (lambda x,y: min((lambda a,b,c: math.hypot(a-x,b-y)/c)(*map(int, f().split())) for _ in range(int(f()))))(*map(int, f().split()))