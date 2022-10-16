import sys
n = int(raw_input())
s = raw_input().rstrip()

a = s.count("A")
c = s.count("C")
g = s.count("G")
t = s.count("T")
q = s.count("?")

make = 4*max(a,c,g,t)
have = a+c+g+t
if make - have > q or (q - (make - have)) % 4 != 0:
	print "==="
	sys.exit(0)

ans = ""
for i in range(len(s)):
	if s[i] == '?':
		if a == min(a,c,g,t):
			ans += 'A'
			a += 1
		elif c == min(a,c,g,t):
			ans += 'C'
			c += 1
		elif g == min(a,c,g,t):
			ans += 'G'
			g += 1
		elif t == min(a,c,g,t):
			ans += 'T'
			t += 1
	else:
		ans += s[i]

print ans