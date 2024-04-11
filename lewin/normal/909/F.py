from itertools import permutations

# for i in xrange(1,12):
# 	for p in permutations(range(1,i+1)):
# 		bad1 = False
# 		bad2 = False
# 		for j in range(i):
# 			if (j+1) == p[j] or ((j+1)&p[j]) != 0:
# 				bad1 = True
# 			if (j+1) == p[j] or ((j+1)&p[j]) == 0:
# 				bad2 = True
		# if not bad1:
		# 	print "A: ",i,p
		# if not bad2:
		# 	print "B: ",i,p


n = int(raw_input())

x = n+2

if n % 2 == 0:
	print "YES"
	ans = [0 for __ in xrange(n)]
	big = n
	while big > 0:
		x = len(bin(big))-2
		small = (1 << x) - big - 1
		for i in range(small, big+1):
			ans[i-1] = big + small - i
		big = small - 1
	print " ".join(map(str,ans))
else:
	print "NO"

if n <= 5 or (n & (n - 1)) == 0:
	print "NO"
else:
	x = len(bin(n)) - 2
	import random
	import sys
	itts = 0
	while itts <= 100:
		itts += 1
		buckets = [[] for __ in xrange(x)]
		for i in range(1,n+1):
			s = [j for j in range(x) if ((i >> j) & 1) == 1]
			buckets[random.choice(s)].append(i)
		if all(len(g) > 1 for g in buckets):
			ans = [0 for __ in xrange(n)]
			for b in buckets:
				for i in range(len(b)):
					ans[b[i]-1] = b[i-1]
			print "YES"
			print " ".join(map(str,ans))
			sys.exit(0)
	print "NO"