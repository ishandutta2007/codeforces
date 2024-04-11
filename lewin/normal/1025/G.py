mod = 1000000007

n = int(raw_input())
arr = map(int, raw_input().split())

followers = [0 for __ in xrange(n+1)]
for x in arr:
	if x != -1:
		followers[x] += 1

final_pot = (pow(2, n-1, mod) - 1) % mod
current_pot = sum((pow(2, x, mod) - 1) % mod for x in followers)

print (final_pot - current_pot) % mod