import math

a=raw_input()
b=raw_input()
n=len(a)
m=len(b)

if a==b:
    print -1
else:
    print max(n,m)