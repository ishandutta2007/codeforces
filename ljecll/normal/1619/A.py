tc = int(input())

for i in range(tc):
	s = str(input())
	if (len(s) % 2 != 0):
		print("NO")
		continue
	n = len(s) // 2
	print("YES" if (s[:n] == s[n:]) else "NO")