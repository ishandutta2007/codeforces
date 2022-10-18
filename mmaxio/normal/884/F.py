from collections import Counter

r = lambda: map(int, input().split())

def main():
	n, = r()
	s = input()
	cost = list(r())

	ans = 0

	cnt = Counter()

	for i in range(n // 2):
		if s[i] == s[n - 1 - i]:
			ans += min(cost[i], cost[n - 1 - i])
			cnt[s[i]] += 1
	total = sum(cnt.values())
	if total > 0:
		ch, occ = cnt.most_common(1)[0]
		avail = []
		if occ > total - occ:
			for i in range(n // 2):
				if s[i] != s[n - 1 - i] and s[i] != ch and s[n - 1 - i] != ch:
					avail.append(min(cost[i], cost[n - 1 - i]))
			avail.sort()
			ans += sum(avail[:2 * occ - total])

	print(sum(cost) - ans)

main()