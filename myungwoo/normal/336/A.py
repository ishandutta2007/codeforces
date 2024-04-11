def sign(n): return 1 if n >= 0 else -1
x,y = map(int,raw_input().split())
a = (abs(x)+abs(y))
if y > 0:
    x1,y1 = 0,a
else:
    x1,y1 = 0,-a
if x > 0:
    x2,y2 = a,0
else:
    x2,y2 = -a,0

if x1 > x2:
    x1,x2 = x2,x1
    y1,y2 = y2,y1
print x1,y1,x2,y2