s = str(input())

ab = len(s)
ba = 0

for i in range(len(s) - 1):
	if (s[i] == 'A' and s[i + 1] == 'B'):
		ab = i
		break
for i in range(len(s) - 2, -1, -1):
	if (s[i] == 'B' and s[i + 1] == 'A'):
		ba = i
		break

if (ba > ab + 1):
	print("YES")
	exit()

ab = 0
ba = len(s)

for i in range(len(s) - 1):
	if (s[i] == 'B' and s[i + 1] == 'A'):
		ba = i
		break
for i in range(len(s) - 2, -1, -1):
	if (s[i] == 'A' and s[i + 1] == 'B'):
		ab = i
		break

if (ab > ba + 1):
	print("YES")
	exit()

print("NO")