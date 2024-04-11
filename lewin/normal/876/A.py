n = int(raw_input())
a = int(raw_input())
b = int(raw_input())
c = int(raw_input())

if n == 1:
    print 0
elif a <= b and a <= c:
    print a * (n-1)
elif b <= a and b <= c:
    print b * (n-1)
else:
    print c * max(0,(n - 2)) + min(a,b)