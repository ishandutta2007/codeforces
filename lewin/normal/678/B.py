import sys

def r():
	return sys.stdin.readline()

def is_leap(y):
	return y % 400 == 0 or (y % 4 == 0 and y % 100 != 0)

x = int(r())

off = 365 if not is_leap(x) else 366
y = x+1
while True:

	if off % 7 == 0 and is_leap(x) == is_leap(y):
		break
	if is_leap(y):
		off += 366
	else:
		off += 365
	y += 1

print y