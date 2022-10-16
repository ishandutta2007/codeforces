import sys
s = raw_input().strip()
seen = [False for _ in range(26)]
for c in s:
	d = ord(c)-ord('a')
	for x in range(d):
		if not seen[x]:
			print "NO"
			sys.exit(0)
	seen[d] = True
print "YES"