x,y=map(int,raw_input().split())
if x>0 and y>0:
    print 0,x+y,x+y,0
elif x<0 and y<0:
    print x+y,0,0,x+y
elif x>0 and y<0:
    print 0,y-x,x-y,0
else:
    print x-y,0,0,y-x