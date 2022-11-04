from sys import stdout, stdin

l = int(stdin.readline())
s = stdin.readline()

i = l // 2
j = (l + 1) // 2

while 1:
	if i >= 0 and s[i] != '0' and s[j] != '0' and j < l:
		x = int(s[:i]) + int(s[i:])
		y = int(s[:j]) + int(s[j:])
		if x < y:
			stdout.write(str(x))
		else:
			stdout.write(str(y))
		break
	elif i >= 0 and s[i] != '0':
		x = int(s[:i]) + int(s[i:])
		stdout.write(str(x))
		break
	elif j < l and s[j] != '0':
		x = int(s[:j]) + int(s[j:])
		stdout.write(str(x))
		break
	i -= 1
	j += 1