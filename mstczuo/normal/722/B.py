n = int(raw_input())
p = map(int, raw_input().strip().split(' '))
s = {'a', 'e', 'i', 'o', 'u', 'y'}

def count_all(word):
	return sum([word.count(c) for c in s])

flag = True
for i in range(n):
	text = raw_input().strip().split(' ')
	text = filter(count_all, text)
	tot = sum(map(count_all, text))
	if tot != p[i]:
		flag = False

print "YES" if flag else "NO"