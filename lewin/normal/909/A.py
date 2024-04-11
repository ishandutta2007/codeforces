s,t = raw_input().split()

i = 1
ans = s[0]
while (i < len(s) and s[i] < t[0]):
	ans += s[i]
	i += 1
ans += t[0]
print ans