from random import shuffle

def main():

	n = int(input())
	a = sorted([(x, i + 1) for i, x in enumerate(map(int, input().split()))])

	ways = 1
	i = 0

	parts = []

	while i < n:
		j = i
		while j < n and a[j][0] == a[i][0]:
			j += 1
		parts.append(a[i : j])
		ways = min(ways * (j - i), 3)
		i = j

	if ways < 3:
		print('NO')
		return

	print('YES')
	outp = set()
	for _ in range(3):
		while True:
			cur = []
			for x in parts:
				shuffle(x)
				cur.extend([t[1] for t in x])
			#print(tuple(cur))
			if tuple(cur) not in outp:
				print(' '.join(map(str, cur)))
				outp.add(tuple(cur))
				break

main()