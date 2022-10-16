mod = 1000000007

n = int(raw_input())

arr = map(int, raw_input().split())

pp = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31]
rr = [37, 41, 43, 47, 53, 59, 61, 67]

cc = [0 for __ in xrange(len(rr))]
freq = [0 for i in range(1<<len(pp))]
for i in range(n):
	msk = 0
	idx = 0
	f = False
	for j in range(len(rr)):
		if arr[i] == rr[j]:
			cc[j] += 1
			f = True
	if f: continue


	for k in pp:
		c = 0
		while arr[i] % k == 0:
			arr[i] /= k
			c ^= 1
		msk |= c << idx
		idx += 1
	freq[msk] += 1

dp = [0 for i in range(1 << len(pp))]
dp[0] = 1
for num in range(1 << len(pp)):
	if freq[num] > 0:
		ndp = [0 for i in range(1 << len(pp))]
		mult = pow(2, freq[num] - 1, mod)

		for i in range(1 << len(pp)):
			ndp[i] = (ndp[i] + dp[i] * mult) % mod
			ndp[i] = (ndp[i] + dp[i^num] * mult) % mod
		dp = ndp


ans = dp[0]
for x in cc:
	if x > 0:
		ans = ans * pow(2, x - 1, mod) % mod

print (ans - 1 + mod) % mod