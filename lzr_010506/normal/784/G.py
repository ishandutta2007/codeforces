n = str(eval(input()))
for j in n:
	for _ in range(ord(j)): print('+') 
	print('.')
	for _ in range(ord(j)): print('-')