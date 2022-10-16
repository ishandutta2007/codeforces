n = int(raw_input())

a = [map(int, raw_input().split()) for __ in range(n)]

import sys
for x in range(n):
    for y in range(n):
        if a[x][y] != 1:
            ok = False
            for s in range(n):
                for t in range(n):
                    if a[x][s] + a[t][y] == a[x][y]:
                        ok = True
            if not ok:
                print "No"
                sys.exit(0)
print "Yes"