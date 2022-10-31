import sys

s = input()
n = len(s)

for i in range(n):
	t =  s[i:] + s[:i] 
	if t != s and t == t[::-1]:
		print(1)
		sys.exit(0)

if s[:n//2] != s[n-n//2:]:
	print(2)
	sys.exit(0)

is4 = True

for i in range(n):
	if not (n % 2 == 1 and i == n//2):
		if s[i] != s[0]:
			is4 = False

if is4 == False:
	print(2)
else:
	print("Impossible")