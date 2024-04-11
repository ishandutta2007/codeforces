import sys
n = int(raw_input())

cpos = 0

for __ in range(n):
    x = raw_input().split()
    
    t = int(x[0])
    dir = x[1]
    
    if dir == "South":
        if cpos + t > 20000:
            print "NO"
            sys.exit(0)
        cpos += t
    elif dir == "East":
        if cpos == 0 or cpos == 20000:
            print "NO"
            sys.exit(0)
    elif dir == "North":
        if cpos - t < 0:
            print "NO"
            sys.exit(0)
        cpos -= t
    elif dir == "West":
        if cpos == 0 or cpos == 20000:
            print "NO"
            sys.exit(0)

if cpos != 0:
    print "NO"
else:
    print "YES"