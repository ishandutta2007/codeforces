a = raw_input()
b = raw_input()
s = raw_input()

res = ""

for c in s:
	if c.isdigit():
		res += c
		continue
		
	i = a.find(c.lower())
	if c.islower():
		res += b[i]
	else:
		res += b[i].upper()

print res