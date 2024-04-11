k=int(raw_input())
r="8"*(k/2)
if k%2:
	r+='4'
if len(r)<=18:
	print r
else:
	print -1