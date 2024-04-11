n = input()
s = ""
if (n % 2 == 1):
	s = s + "7"
	n -= 3

while (n > 0):
	s = s + "1"
	n -= 2

print s