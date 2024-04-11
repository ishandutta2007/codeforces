def diff(s):
	return [s[i] - s[i - 1] for i in range(1, len(s))]

def main():
	n, m = map(int, input().split())
	if m > n:
		return 0
	if m == 1:
		return n
	t = diff(list(map(int, input().split())))
	p = diff(list(map(int, input().split())))
	w = p + [10**9] + t
	ret = 0
	pi = [0] * len(w)
	for i in range(1, len(w)):
		j = pi[i - 1]
		while j > 0 and w[i] != w[j]:
			j = pi[j - 1];
		if w[i] == w[j]:
			j += 1
		pi[i] = j
		if j == len(p):
			ret += 1
	return ret

print(main())