n = int(raw_input())
s = raw_input().rstrip()
print "".join(map(str, map(len, s.split("0"))))