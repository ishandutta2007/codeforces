from collections import defaultdict

n,x,k = map(int, raw_input().split())
arr = sorted(map(int, raw_input().split()))

s = defaultdict(int)
freq = defaultdict(int)
ans = 0
for i in range(n):
	b = arr[i] / x
	ans += s[b - k + 1]
	s[(arr[i] + x - 1) / x] += 1
	freq[arr[i]] += 1

for a,b in freq.iteritems():
	c = 1 if a % x == 0 else 0
	if c == k:
		ans += b * (b - 1) / 2 + b
print ans