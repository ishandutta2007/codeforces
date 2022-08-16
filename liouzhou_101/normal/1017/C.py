n = int(input())
L = int(n**.5)
s = []
for cur in range(0, n, L):
	s +=list(range(min(cur+L, n), cur, -1))
print(' '.join(map(str, s)))