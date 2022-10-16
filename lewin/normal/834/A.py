a,b = raw_input().split()
n = int(raw_input())
x = "v<^>"
if a == b:
    print "undefined"
elif set([a,b]) == set("<>"):
    print "undefined"
elif set([a,b]) == set("^v"):
    print "undefined"
else:
    r = x.index(a)
    if x[(r+n)%4] == b:
        print "cw"
    else:
        print "ccw"