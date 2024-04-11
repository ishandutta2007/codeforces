n, k = map(int, raw_input().split())
n %= 2 * k
if n >= k:
    print "YES"
else:
    print "NO"