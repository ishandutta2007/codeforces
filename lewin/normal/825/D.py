s,t = raw_input(), raw_input()

freqf = [0 for __ in xrange(26)]
for c in t:
	freqf[ord(c) - ord('a')] += 1

freqs = [0 for __ in xrange(26)]
nq = 0
for c in s:
	if c == '?':
		nq += 1
	else:
		freqs[ord(c) - ord('a')] += 1

lo = 0
hi = 1000000
while lo < hi:
	mid = (lo+hi+1) / 2
	need = 0
	for x in range(26):
		need += max(freqf[x] * mid - freqs[x], 0)
	
	if need <= nq: lo = mid
	else: hi = mid-1

b = [s[i] for i in range(len(s))]
nn = [max(freqf[x] * lo - freqs[x], 0) for x in range(26)]
idx = 0
for i in range(len(s)):
	if b[i] == '?':
		while idx < 26 and nn[idx] == 0: idx += 1
		if idx == 26: b[i] = 'a'
		else: b[i] = chr(idx+ord('a'))
		if idx < 26: nn[idx] -= 1

print "".join(b)