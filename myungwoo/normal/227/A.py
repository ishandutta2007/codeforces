x1,y1 = map(int,raw_input().split())
x2,y2 = map(int,raw_input().split())
x3,y3 = map(int,raw_input().split())

v = (x2-x1)*(y3-y1)-(x3-x1)*(y2-y1)

if v < 0: print 'RIGHT'
elif v > 0: print 'LEFT'
else: print 'TOWARDS'