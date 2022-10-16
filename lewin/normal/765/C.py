k,a,b = map(int, raw_input().split())

if (a < k and b < k) or (a % k != 0 and b < k) or (b % k != 0 and a < k):
	print -1
else:
	print a/k+b/k