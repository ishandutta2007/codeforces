import sys
import re

f = sys.stdin

def isNum(x):
    return len(x) > 0 and (x[0] != '0' or len(x) == 1) and all('0' <= c <= '9' for c in x)
p = re.compile('[,;]')
tokens = p.split(f.readline().rstrip("\n"))

nums = [x for x in tokens if isNum(x)]
nonnums = [x for x in tokens if not isNum(x)]

def printList(y):
    if y: print "\"" + ",".join(y) + "\""
    else: print "-"

printList(nums)
printList(nonnums)