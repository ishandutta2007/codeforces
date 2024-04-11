n = int(raw_input())
a = map(int, raw_input().split())
a.sort()
if a[n] == a[n - 1]: print "NO"
else: print "YES"