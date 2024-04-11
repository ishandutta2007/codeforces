n,m = map(int, raw_input().split())
a = set(map(int, raw_input().split()))
b = set(map(int, raw_input().split()))

if len(a & b) == 0:
    s = min(a)
    t = min(b)
    if s > t:
        print t*10+s
    else:
        print s*10+t
else:
    print min(a&b)