from sys import stdout

c = int(raw_input())
s = raw_input()
c = 0
for h in s:
	if h in "aeiouy":
		c+=1
	else:
		c = 0
	if c < 2:
		stdout.write(h)
print