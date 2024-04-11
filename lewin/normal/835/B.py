k = int(raw_input())

s = raw_input().strip()

freq = [0 for __ in xrange(10)]
ss = 0
for c in s:
	freq[ord(c)-ord('0')] += 1
	ss += ord(c) - ord('0')

ans = 0
for i in xrange(9):
	if ss < k:
		x = min((k-ss+9-i-1) / (9-i), freq[i])
		ans += x
		ss += x * (9-i)

print ans