n = int(raw_input())
a = map(int, raw_input().split())
if sum(a) % 2 == 1 or any(x % 2 == 1 for x in a):
    print "First"
else:
    print "Second"