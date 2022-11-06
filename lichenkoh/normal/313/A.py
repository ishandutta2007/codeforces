s = raw_input()
news = s[:-1]
oldn = int(s)
if (oldn >= 0):
	print oldn
else:
	newn = int(news)
	if len(s) <= 2:
		print max(newn,oldn)
	else:
		news2 = s[:-2] + s[-1]
		newn2 = int(news2)
		print max(newn2,max(newn,oldn))