n = int(raw_input())
arr = map(int, raw_input().split())
seen = [False] * (n+1)
back = n
for x in arr:
	seen[x] = True
	add = []
	while (back > 0 and seen[back]):
		add.append(back)
		back -= 1
	print " ".join(map(str,add))