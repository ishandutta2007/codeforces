from sys import stdout, stdin

s = stdin.readline()

res = 0
for c in s:
	if c in "aeiou13579":
		res += 1

stdout.write(str(res)+'\n')