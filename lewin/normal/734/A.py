n = int(raw_input())
s = raw_input().rstrip()
a = s.count("A")
d = s.count("D")
if a > d:
  print "Anton"
elif d > a:
  print "Danik"
else:
  print "Friendship"