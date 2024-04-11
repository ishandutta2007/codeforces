n = int(raw_input())
p = map(int, raw_input().split())

ans = [n]
cp = n
while cp != 1:
	cp = p[cp-2]
	ans.append(cp)

print " ".join(map(str,ans[::-1]))