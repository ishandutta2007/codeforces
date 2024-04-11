a,b = map(int, raw_input().split())

if b - a >= 10:
    print 0
else:
    x = 1
    for i in range(a+1,b+1):
        x = x * i % 10
    print x