n,k = map(int, raw_input().split())
s = raw_input()

import sys
for i in "qwertyuiopasdfghjklzxcvbnm":
    if s.count(i) > k:
        print "NO"
        sys.exit(0)
print "YES"