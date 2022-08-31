s=[raw_input()for i in range(input())]
c=[chr(i+97)for i in range(26)]
for x in c:
	if sum(t.count(x)for t in s)==0:
		print x
		exit()
for x in c:
	for y in c:
		if sum(t.count(x+y)for t in s)==0:
			print x+y
			exit()