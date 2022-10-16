import sys
k,a,b = map(int, sys.stdin.readline().split(" "))

def count(x):
    return x//k

if a <= 0 and b >= 0:
    print count(-a)+count(b)+1
elif a > 0 and b > 0:
    print count(b) - count(a-1)
else:
    print count(-a)-count(-b-1)